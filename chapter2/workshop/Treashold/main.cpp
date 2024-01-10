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

#include <chrono>
#include <QDebug>


cv::Mat makeThreshold(cv::Mat img)
{
    cv::Mat greyMat;
    cv::cvtColor(img, greyMat, cv::COLOR_BGR2GRAY);

    cv::Mat out;
    cv::threshold( greyMat, out,  127, 255, cv::THRESH_BINARY);

    return out;
}


cv::Mat makeAdaptiveThreshold(cv::Mat img)
{
    cv::Mat out;

    cv::Mat greyMat;
    cv::cvtColor(img, greyMat, cv::COLOR_BGR2GRAY);

    cv::adaptiveThreshold(greyMat,out,
                          255,
                          cv::ADAPTIVE_THRESH_MEAN_C,
                            cv::THRESH_BINARY,7,2);

    return out;



}


cv::Mat makeThresholdOcu(cv::Mat img)
{
    cv::Mat greyMat;
    cv::cvtColor(img, greyMat, cv::COLOR_BGR2GRAY);

    cv::Mat out;
    cv::threshold( greyMat, out,  0, 255, cv::THRESH_BINARY+cv::THRESH_OTSU);

    return out;
}


/*
# Otsu's thresholding
ret2,th2 = cv.threshold(img,0,255,cv.THRESH_BINARY+cv.THRESH_OTSU)
*/
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath="../Treashold/8.jpeg";
    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat out;
    auto t1 = std::chrono::high_resolution_clock::now();



    // out=makeThreshold(img);
     out=makeThresholdOcu(img);


    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    qDebug() << ms_double.count() << "ms";

    cv::namedWindow(imgPath.toStdString(), cv::WINDOW_AUTOSIZE);
    cv::imshow(imgPath.toStdString(), out);

    return a.exec();
}
