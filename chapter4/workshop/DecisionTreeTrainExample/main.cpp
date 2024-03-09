//***************************************
// Copyright (c) 2024 Konstantin Zvyagin.
// e-mail: knzvyagin@gmail.com
// SPDX-License-Identifier: BSD-3-Clause	
//***************************************

#include <QApplication>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/ml/ml.hpp"

#include <QString>
#include <QPainter>
#include <QLabel>
#include <QFileInfo>
#include <QDebug>
#include <QVector>

#include <cstdio>

/******************************************************************************/
// global definitions (for speed and ease of use)

#define NUMBER_OF_TRAINING_SAMPLES 1383
#define ATTRIBUTES_PER_SAMPLE 6  // not the last as this is the class
#define NUMBER_OF_TESTING_SAMPLES 345

#define NUMBER_OF_CLASSES 4 // classes 0->3
static char* CLASSES[NUMBER_OF_CLASSES] =
{(char *) "unacc", (char *) "acc", (char *) "good", (char *) "vgood"};

using namespace cv;

using namespace  cv::ml;

// a basic hash function from: http://www.cse.yorku.ca/~oz/hash.html

int hash(char *str)
{
    int hash = 5381;
    int c;

    while ((c = (*str++)))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}



QVector<float> toArray(cv::Mat &img)
{
    QVector<float> res;

    float_t* pixelPtr = (float_t*)img.data;
    int cn = img.channels();
    Scalar_<uint8_t> bgrPixel;

    for(int i = 0; i < img.rows; i++)
    {
        for(int j = 0; j < img.cols; j++)
        {
            for(int d=0; d< img.depth() ; d++)
            {
                res << pixelPtr[i*img.cols*cn + j*cn + d];
            }

        }
    }

    return res;
}


/******************************************************************************/

// loads the sample database from file (which is a CSV text file)

int read_data_from_csv(const char* filename, Mat data, Mat classes,
                       int n_samples )
{
    char tmp_buf[10];
    int i = 0;
    char c;

    // if we can't read the input file then return 0
    FILE* f = fopen( filename, "r" );
    if( !f )
    {
        printf("ERROR: cannot read file %s\n",  filename);
        return 0; // all not OK
    }

    // for each sample in the file

    for(int line = 0; line < n_samples; line++)
    {

        // for each attribute on the line in the file

        for(int attribute = 0; attribute < (ATTRIBUTES_PER_SAMPLE + 1); attribute++)
        {
            // last attribute is the class

            if (attribute == 6)
            {
                c = '\0';
                for(i=0; c != '\n'; i++)
                {
                    c = fgetc(f);
                    tmp_buf[i] = c;
                }
                tmp_buf[i - 1] = '\0';
                //printf("%s\n", tmp_buf);

                // find the class number and record this

                for (int i = 0; i < NUMBER_OF_CLASSES; i++)
                {
                    if (strcmp(CLASSES[i], tmp_buf) == 0)
                    {
                        classes.at<float>(line, 0) = (float) i;
                    }
                }
            }
            else
            {

                // for all other attributes just read in the string value
                // and use a hash function to convert to to a float
                // (N.B. openCV uses a floating point decision tree implementation!)

                c = '\0';
                for(i=0; c != ','; i++)
                {
                    c = fgetc(f);
                    tmp_buf[i] = c;
                }
                tmp_buf[i - 1] = '\0';
                data.at<float>(line, attribute) = (float) hash(tmp_buf);

                //printf("%s,", tmp_buf);
            }
        }
    }

    fclose(f);

    return 1; // all OK
}

void buildTree()
{
    // define training data storage matrices (one for attribute examples, one
    // for classifications)

    Mat training_data = Mat(NUMBER_OF_TRAINING_SAMPLES, ATTRIBUTES_PER_SAMPLE, CV_32FC1);
    Mat training_classifications = Mat(NUMBER_OF_TRAINING_SAMPLES, 1, CV_32FC1);

    //define testing data storage matrices

    Mat testing_data = Mat(NUMBER_OF_TESTING_SAMPLES, ATTRIBUTES_PER_SAMPLE, CV_32FC1);
    Mat testing_classifications = Mat(NUMBER_OF_TESTING_SAMPLES, 1, CV_32FC1);

    // define all the attributes as categorical (i.e. categories)
    // alternatives are cv::ml::VAR_CATEGORICAL
    // that can be assigned on a per attribute basis

    // this is a classification problem (i.e. predict a discrete number of class
    // outputs) so also the last (+1) output var_type element to cv::ml::VAR_CATEGORICAL

    Mat var_type = Mat(ATTRIBUTES_PER_SAMPLE + 1, 1, CV_8U );
    var_type = Scalar(cv::ml::VAR_CATEGORICAL); // all inputs are categorical

cv:ml::DTrees::Node* resultNode; // node returned from a prediction

    // load training and testing data sets

    QString training_data_name = "car.train" ;
    QString testing_data_name  = "car.test"  ;

    bool read1_ok=read_data_from_csv(training_data_name.toLocal8Bit().data(), training_data, training_classifications, NUMBER_OF_TRAINING_SAMPLES);
    bool read2_ok=read_data_from_csv(testing_data_name.toLocal8Bit().data(), testing_data, testing_classifications, NUMBER_OF_TESTING_SAMPLES);

    if( !read1_ok || ! read2_ok )
    {
        qDebug()<<"ERROR can't load datasets:"<< training_data_name << testing_data_name ;
        return;
    }


    // define the parameters for training the decision tree

    float priors[] = { 1, 1, 1, 1 }; // weights of each classification for classes
    cv::Mat mpriors(1,4,CV_32FC1,priors);
    //float priors[] = { 70, 22, 4, 4 }; // weights of each classification for classes

    /*   CvDTreeParams params = cv::ml::DTreesParams(25, // max depth
                                             10, // min sample count
                                             0, // regression accuracy: N/A here
                                             false, // compute surrogate split, no missing data
                                             25, // max number of categories (use sub-optimal algorithm for larger numbers)
                                             10, // the number of cross-validation folds
                                             true, // use 1SE rule => smaller tree
                                             false, // throw away the pruned tree branches
                                             priors // the array of priors, the bigger weight, the more attention
                                             // to the maligant cases
                                             // (i.e. a case will be judjed to be maligant with bigger chance)
                                            );
*/

    qDebug()<< "Using training database:"<<training_data_name;
    Ptr<DTrees> dtree=cv::ml::DTrees::create();

    // set tree params before training
    dtree->setMaxDepth(25);// max dtree depth //to experimet set to 3
    dtree->setMinSampleCount(10);// min sample count
    dtree->setRegressionAccuracy(0);// regression accuracy: N/A here
    dtree->setUseSurrogates(false);// compute surrogate split, no missing datas
    dtree->setMaxCategories(25);// max number of categories (use sub-optimal algorithm for larger numbers)
    dtree->setCVFolds(1);      // the number of cross-validation folds  ;
    dtree->setUse1SERule(true);// use 1SE rule => smaller tree
    dtree->setTruncatePrunedTree(false);// throw away the pruned tree branches
    dtree->setPriors(mpriors);// the array of priors, the bigger weight, the more attention
    // to the maligant cases
    // (i.e. a case will be judjed to be maligant with bigger chance)

    Ptr<TrainData> trainData= TrainData::create(training_data,SampleTypes::ROW_SAMPLE, training_classifications);
    qDebug()<<"start trining...";

    dtree->train( trainData );

    qDebug()<<"trining done!";



    // perform classifier testing and report results

    Mat test_sample;
    int correct_class = 0;
    int wrong_class = 0;
    int false_positives [NUMBER_OF_CLASSES] = {0,0,0,0};


    qDebug()<<"Using testing database:"<< testing_data_name;

    for ( int tsample = 0;
          tsample < NUMBER_OF_TESTING_SAMPLES;
          tsample++ )
    {

        // extract a row from the testing matrix

        test_sample = testing_data.row(tsample);

        // run decision tree prediction


        Mat cresult;
        float fresult = dtree->predict(test_sample,cresult);

        //qDebug()<<"i:"<<tsample<<" rows:"<<cresult.rows<<" cols:"<<cresult.cols<< " depth:"<<cresult.depth()<<"type:"<<cresult.type()<<" toArray:"<<(toArray(cresult));

        //qDebug()<<"Testing Sample"<<tsample<< " -> func result:"<<fresult<<" answer:"<<(testing_classifications.at<float>(tsample, 0));


        // if the prediction and the (true) testing classification are the same
        // (N.B. openCV uses a floating point decision tree implementation!)

        if ( fabs(fresult - testing_classifications.at<float>(tsample, 0))
             >= FLT_EPSILON)
        {
            // if they differ more than floating point error => wrong class

            wrong_class++;

            false_positives[(int) fresult]++;

        }
        else
        {
            // otherwise correct
            correct_class++;
        }
    }

    qDebug() <<"correct_class:"<< correct_class <<" in %:"<<((double) correct_class*100/NUMBER_OF_TESTING_SAMPLES);
    qDebug() <<"wrong_class:"  << wrong_class   <<" in %:"<<((double) wrong_class*100/NUMBER_OF_TESTING_SAMPLES);


    // each class false results:
    for (int i = 0; i < NUMBER_OF_CLASSES; i++)
    {
        qDebug()<< "Class "<<CLASSES[i]
                   << " false postives "<<false_positives[i]
                      << "( " <<((double) false_positives[i]*100/NUMBER_OF_TESTING_SAMPLES)<< ")";
    }

    //TODO calc precsision and accurity

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qDebug() << "OpenCV version:"
             <<CV_VERSION
            <<CV_MAJOR_VERSION<< CV_MINOR_VERSION<< CV_SUBMINOR_VERSION;


    buildTree();
    return a.exec();
}
