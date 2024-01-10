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


cv::Mat makeKanny(cv::Mat src)
{
    int lowThreshold = 75; // 0-100
    const int ratio = 3;
    const int kernel_size = 3;

    cv::Mat edges_dest,src_gray;
    cv::cvtColor( src, src_gray, cv::COLOR_BGR2GRAY );
    cv::blur( src_gray, edges_dest, cv::Size(3,3) );
    cv::Canny( edges_dest, edges_dest, lowThreshold, lowThreshold*ratio, kernel_size );

    cv::namedWindow("edges_dest", cv::WINDOW_AUTOSIZE);
    cv::imshow( "edges_dest", edges_dest );

    return edges_dest;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath="../8.jpeg";
    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat res =makeKanny( img );
    cv::namedWindow(imgPath.toStdString(), cv::WINDOW_AUTOSIZE);
    cv::imshow(imgPath.toStdString(), img);
    cv::waitKey();

    return 0;
}
