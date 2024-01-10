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

#include <QString>
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include <vector>

cv::Mat makeFindConturs(cv::Mat src)
{
    int lowThreshold = 75; // 0-100
    const int ratio = 3;
    const int kernel_size = 3;

    //cv:RNG rng(12345);
    cv::Mat edges_dest,src_gray;
    cv::cvtColor( src, src_gray, cv::COLOR_BGR2GRAY );
    cv::blur( src_gray, edges_dest, cv::Size(3,3) );
    cv::Canny( edges_dest, edges_dest, lowThreshold, lowThreshold*ratio, kernel_size );

    cv::namedWindow("edges_dest", cv::WINDOW_AUTOSIZE);
    cv::imshow( "edges_dest", edges_dest );

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours( edges_dest, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );

    cv::Mat drawing = src;//cv::Mat::zeros( edges_dest.size(), CV_8UC3 );

    for( size_t i = 0; i< contours.size(); i++ )
    {
        //cv::Scalar color = cv::Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
        cv::Scalar color = cv::Scalar( 0, 256, 0 );
        if( hierarchy[i][0] ==1)
            color=cv::Scalar( 0, 0, 255 );
        if( hierarchy[i][1] ==1)
            color=cv::Scalar( 256, 0, 0 );
        if( hierarchy[i][2] ==1)
            color=cv::Scalar( 255, 255, 0 );
        if( hierarchy[i][3] ==1)
            color=cv::Scalar( 0, 256, 255 );

        cv::drawContours( drawing, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0 );
    }

    return drawing;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath="../8.jpeg";
    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat res =makeFindConturs( img );
    cv::namedWindow(imgPath.toStdString(), cv::WINDOW_AUTOSIZE);
    cv::imshow(imgPath.toStdString(), img);
    cv::waitKey();

    return 0;
}
