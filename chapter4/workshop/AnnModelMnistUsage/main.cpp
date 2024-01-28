//***************************************
// Copyright (c) 2024 Konstantin Zvyagin.
// e-mail: knzvyagin@gmail.com
// SPDX-License-Identifier: BSD-3-Clause	
//***************************************

#include <QApplication>
#include <QString>
#include <QDebug>
#include <tuple>

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/ml.hpp"

void printFloatMat(cv::Mat res)
{
    for( int x = 0; x < res.rows; ++x )
    for( int y = 0; y < res.cols; ++y )
    {
        double value=res.at<float>(x, y);
        qDebug()<<"row:"<<x << " col:" << y << " value:"<< value;
    }
}


std::tuple<int,double> extractAnswer(cv::Mat res)
{
    int    number=0;
    double maXvalue=std::numeric_limits<double>::lowest();
    for( int x = 0; x < res.rows; ++x )
    for( int y = 0; y < res.cols; ++y )
    {
        double value=res.at<float>(x, y);
        if( maXvalue < value )
        {
            maXvalue=value;
            number = y;
        }
    }

    return {number,maXvalue};
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath = "mnist_0.png"; // cahnge here name to differnet names to test differrent numbers
    std::string cvImagePath=imgPath.toStdString();
    QString modelPath = "model.xml";

    cv::Ptr<cv::ml::ANN_MLP> ann = cv::ml::ANN_MLP::load(modelPath.toStdString()); // loading our network
    cv::Mat originalImage = cv::imread( cvImagePath, cv::IMREAD_GRAYSCALE);
    cv::Mat imputImage;

    if( (originalImage.cols != originalImage.rows) || (originalImage.rows!= 28) )
    {
        qDebug()<<"Input image sizi is'nt equal 28x28 !!! Breaking processing image";
        cv::Mat asdasd;
        originalImage.convertTo( imputImage,CV_32FC1);//Converting to values scaled as 1.0/255
        imputImage.resize( 28 );

        qDebug()<<"Original mage cols, rows, channels: "<<originalImage.cols<<originalImage.rows<<originalImage.channels();
        qDebug()<<"img2.cols:"<<imputImage.cols<<"img2.rows:"<<imputImage.rows<<"img2.channels():"<<imputImage.channels();
    }else
    {
        qDebug()<<"Original mage cols, rows, channels: "<<originalImage.cols<<originalImage.rows<<originalImage.channels();
        originalImage.convertTo( imputImage,CV_32FC1);//Converting to values scaled as 1.0/255
        qDebug()<<"img2.cols:"<<imputImage.cols<<"img2.rows:"<<imputImage.rows<<"img2.channels():"<<imputImage.channels();
    }

    cv::imshow( "Converted image:", imputImage);
    cv::Mat vector=imputImage.reshape(1,1);

    cv::Mat res ;
    ann->predict( vector, res ); // evaluating our network

    qDebug()<<"Printing result:";
    printFloatMat(res);
    cv::normalize(res, res, 0.0, 1.0, cv::NORM_MINMAX);

    qDebug()<<"Printing result after norm_min_max:";
    printFloatMat(res);


    int number;
    double probolity;

    std::tie( number, probolity ) = extractAnswer(res);
    qDebug()<<"Detected number at image:"<<number<<" with probobility score:"<<probolity;
    std::string windowName="Original image";
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    cv::imshow(windowName, originalImage);

    return a.exec();
}
