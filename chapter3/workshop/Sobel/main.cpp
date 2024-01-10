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


cv::Mat makeSobelByGray(cv::Mat src, bool showSubImages=false)
{
    cv::Mat img2=src, gray, dest;
    cv::Mat grad_x, grad_y, grad_xy;
    cv::Mat abs_grad_x, abs_grad_y , abs_grad_xy;



    //cv::GaussianBlur(src, img2, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT); // removing noise
    cv::cvtColor(img2, gray, cv::COLOR_BGR2GRAY); // make one channel

    int ddepth = CV_16S;
    int ksize =3;
    double scale=1, delta=0;

    cv::Sobel(gray, grad_x, ddepth, 1, 0 , ksize, scale, delta, cv::BORDER_DEFAULT);
    // x order =1 means this type of kernel :
    // | −1  0  1 |
    // | −2  0  2 |
    // | −1  0  1 |
    cv::Sobel(gray, grad_y, ddepth, 0, 1 , ksize, scale, delta, cv::BORDER_DEFAULT);
    // x order =0 means this type of kernel :
    // | −1  −2 -1 |
    // |  0  0   0 |
    // |  1  2   1 |




    cv::convertScaleAbs(grad_x, abs_grad_x); //conversion to an unsigned 8-bit type
    cv::convertScaleAbs(grad_y, abs_grad_y); //conversion to an unsigned 8-bit type

    if( showSubImages )
    {
        cv::namedWindow("grad_x", cv::WINDOW_AUTOSIZE);
        cv::imshow("grad_x", abs_grad_x);
        cv::namedWindow("grad_y", cv::WINDOW_AUTOSIZE);
        cv::imshow("grad_y", abs_grad_y);

        cv::namedWindow("abs_grad_xy", cv::WINDOW_AUTOSIZE);
        cv::imshow("abs_grad_xy", abs_grad_xy);
    }

    cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dest);

    return dest;
}

cv::Mat makeSobelByRGB(cv::Mat src, bool showSubImages=false)
{
    cv::Mat dest1,dest2,dest3,dest;
    cv::Mat b_x, b_y, g_x, g_y, r_x,r_y;
    cv::Mat abs_b_x, abs_b_y , abs_g_x , abs_g_y, abs_r_x, abs_r_y;

    // splitting to 3 channels
    cv::Mat bgrchannel[3];
    cv::split(src,bgrchannel);

    if( showSubImages )
    {
        cv::namedWindow("Blue",cv::WINDOW_AUTOSIZE);
        cv::imshow("Red", bgrchannel[0]);
        cv::namedWindow("Green",cv::WINDOW_AUTOSIZE);
        cv::imshow("Green", bgrchannel[1]);
        cv::namedWindow("Red",cv::WINDOW_AUTOSIZE);
        cv::imshow("Blue", bgrchannel[2]);
    }

    int ddepth = CV_16S;
    int ksize =3;
    double scale=1, delta=0;

    cv::Sobel(bgrchannel[0], b_x, ddepth, 1, 0 , ksize, scale, delta, cv::BORDER_DEFAULT);
    cv::Sobel(bgrchannel[0], b_y, ddepth, 0, 1 , ksize, scale, delta, cv::BORDER_DEFAULT);

    cv::Sobel(bgrchannel[1], g_x, ddepth, 1, 0 , ksize, scale, delta, cv::BORDER_DEFAULT);
    cv::Sobel(bgrchannel[1], g_y, ddepth, 0, 1 , ksize, scale, delta, cv::BORDER_DEFAULT);

    cv::Sobel(bgrchannel[2], r_x, ddepth, 1, 0 , ksize, scale, delta, cv::BORDER_DEFAULT);
    cv::Sobel(bgrchannel[2], r_y, ddepth, 0, 1 , ksize, scale, delta, cv::BORDER_DEFAULT);


    cv::convertScaleAbs(b_x, abs_b_x);
    cv::convertScaleAbs(b_x, abs_b_y);
    cv::convertScaleAbs(g_x, abs_g_x);
    cv::convertScaleAbs(g_y, abs_g_y);
    cv::convertScaleAbs(r_x, abs_r_x);
    cv::convertScaleAbs(r_y, abs_r_y);


    cv::addWeighted(abs_b_x, 0.5, abs_b_y, 0.5, 0, dest1);
    cv::addWeighted(abs_g_x, 0.5, abs_g_y, 0.5, 0, dest2);
    cv::addWeighted(abs_r_x, 0.5, abs_r_y, 0.5, 0, dest3);

    dest=dest1+dest2+dest3;
    return dest;


}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    qDebug()<<"cv version:"<<CV_VERSION;

    bool GRAY_EXAMPLE=true;
    //******GRAY**************************************************************//
    if(GRAY_EXAMPLE){
        QString imgPath="../8.png";
        cv::Mat img = cv::imread( imgPath.toStdString() );
        cv::imshow(imgPath.toStdString() , img);

        auto t1 = std::chrono::high_resolution_clock::now();

        cv::Mat destGray=makeSobelByGray( img );

        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        qDebug() << ms_double.count() << "ms";

        cv::namedWindow("destGray", cv::WINDOW_AUTOSIZE);
        cv::imshow("destGray", destGray);
    }




    bool BGR_EXAMPLE=false;
    //******RGB**************************************************************//
    if(BGR_EXAMPLE){
        QString imgPath="../bgr.png";
        cv::Mat img = cv::imread( imgPath.toStdString() );

        auto t1 = std::chrono::high_resolution_clock::now();

        cv::Mat destBGR=makeSobelByRGB( img, false );

        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        qDebug() << ms_double.count() << "ms";

        cv::namedWindow("destBGR", cv::WINDOW_AUTOSIZE);
        cv::imshow("destBGR", destBGR);

    }

    return a.exec();
}

