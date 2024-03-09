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
#include "opencv2/opencv.hpp"
#include "opencv2/ml.hpp"
using namespace cv;
using namespace ml;

#include <QString>
#include <QPainter>
#include <QLabel>
#include <QDebug>

void train_and_predict_NN()
{
    //Training data and corresponding labels
     float trainingData[8][2] = {{480,500},{50,130},{110,32},{490,60},{60,190},{200,189},{78,256},{45,315}};
     float labels[8] = {0,1,0,0,1,0,1,1};
     Mat trainingDataMat(8, 2, CV_32FC1, trainingData);
     Mat labelsMat(8, 1, CV_32FC1, labels);
     //Modeling
     Ptr<ANN_MLP> model = ANN_MLP::create();
     //A total of 5 layers: input layer + 3 hidden layers + 1 output layer, each of the input layer and hidden layer has 2 perceptrons
     Mat layerSizes = (Mat_<int>(1, 5) << 2, 2, 2, 2, 1);
     //Set the number of neurons in each layer
     model->setLayerSizes(layerSizes);
     //Activation function
     model->setActivationFunction(ANN_MLP::SIGMOID_SYM);
     //MLP training method
     model->setTrainMethod(ANN_MLP::BACKPROP,0.1,0.9);
     //Training model
     Ptr<TrainData> trainData = TrainData::create(trainingDataMat, ROW_SAMPLE, labelsMat);
     model->train(trainData);

     Mat src = Mat::zeros(512, 512, CV_8UC3);
     for (int i = 0; i < src.rows; i++)
     {
         for (int j = 0; j < src.cols; j++)
         {
             Mat sampleMat = (Mat_<float>(1, 2) << i, j);
             Mat responseMat;
             model->predict(sampleMat, responseMat);
             float p = responseMat.ptr<float>(0)[0];
             if (p> 0.5)
                 src.at<Vec3b>(j, i) = Vec3b(0,125,125);
             else
                 src.at<Vec3b>(j, i) = Vec3b(125,125,0);
         }
     }
     //Draw the distribution of training data in the graph
     Mat dst1 = src.clone();
     for (int i = 0; i < sizeof(trainingData[0]); i++)
     {
         float q = labels[i];
         //Draw different colors according to the labels corresponding to the training data: 1 corresponds to red, 0 corresponds to green
         if (q == 1)
             circle(dst1, Point(trainingData[i][0],trainingData[i][1]), 5, Scalar(0,0,255), -1, 8);
         else
             circle(dst1, Point(trainingData[i][0],trainingData[i][1]), 5, Scalar(0,255,0), -1, 8);
     }
     // Randomly generate 20 points within the range of the original image, and use the trained neural network to predict them, and draw the prediction results
     Mat dst2 = src.clone();
     for (int i = 0; i < 100; i++)
     {

         RNG rngx(i);
         float x = rngx.uniform(0,512);
         RNG rngy(i*i);
         float y = rngy.uniform(0,512);

         Mat trainingDataMat = (Mat_<float>(1,2)<<x,y);
         Mat response;
         model->predict(trainingDataMat,response);
         float q = response.ptr<float>(0)[0];
         if (q > 0.5)
             circle(dst2, Point(x,y), 5, Scalar(0,0,255), -1, 8);
         else
             circle(dst2, Point(x,y), 5, Scalar(0,255,0), -1, 8);
     }

     cv::namedWindow("Distribution of training data", cv::WINDOW_AUTOSIZE);
     imshow("Distribution of training data", dst1);

     cv::namedWindow("Randomly generated points and predict them", cv::WINDOW_AUTOSIZE);
     imshow("Randomly generated points and predict them", dst2);

     waitKey(0);


}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    train_and_predict_NN();

    return a.exec();
}
