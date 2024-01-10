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

cv::Mat drawHist(cv::Mat *histLayers, int channels, int histSize , int histWidth=256*3, int histHeight=400)
{
    cv::Mat histImg(histHeight, histWidth, CV_8UC3,   cv::Scalar(255, 255, 255));

    cv::Scalar colors[] = {cv::Scalar(255, 0, 0),
       cv::Scalar(0, 255, 0), cv::Scalar(0, 0, 255)}; // цвета для рисования

    for(int i=0;i< channels; i++)
    {
        // нормализация гистограмм в соответствии с размерам
        cv::normalize(histLayers[i], histLayers[i], 0, histImg.rows, cv::NORM_MINMAX, -1, cv::Mat());
    }

    // отрисовка гистограмме на холсте
    int binWidth = cvRound((double)histWidth / histSize);// количество пикселей на бин
    for (int i = 1; i < histSize; i++)
    {
        for(int k=0;k< channels; k++)
        {
            cv::line( histImg
                     , cv::Point(binWidth * (i-1),  histHeight-cvRound(histLayers[k].at<float>(i-1)))
                     , cv::Point(binWidth * i, histHeight-cvRound(histLayers[k].at<float>(i)) )
                     , colors[k], 2, 8, 0);
        }
    }

    return histImg;
}


cv::Mat makeCalcHist(cv::Mat src , bool showHist=false )
{
     int histSize = 256; // количество столбцов гистограммы
     float range[] = {0.0f, 256.0f};// интервал изменения значений одного столбца
     const float* histRange = { range };
     bool uniform = true;// равномерное распределение интервала по столбцам
     bool accumulate = false;// каждая гистограмма отдельно

     cv::Mat bgrChannels[3];
     cv::Mat bgrHist[3];

     cv::split(src, bgrChannels);     // разделяем на независимые каналы


     // вычисление гистограммы для каждого канала
     cv::calcHist(&bgrChannels[0], 1, 0, cv::Mat(), bgrHist[0], 1, &histSize, &histRange, uniform, accumulate);
     cv::calcHist(&bgrChannels[1], 1, 0, cv::Mat(), bgrHist[1], 1, &histSize, &histRange, uniform, accumulate);
     cv::calcHist(&bgrChannels[2], 1, 0, cv::Mat(), bgrHist[2], 1, &histSize, &histRange, uniform, accumulate);

     cv::Mat histImg=drawHist( bgrHist, 3, 256 );

     if(showHist)
     {
        cv::namedWindow("src",   cv::WINDOW_AUTOSIZE);
        cv::namedWindow("hist:", cv::WINDOW_AUTOSIZE);
        cv::imshow("src", src);
        cv::imshow("hist:", histImg);
     }

     return histImg;
}

cv::Mat makeEqualizeByHist(cv::Mat src , bool show=false)
{
    cv::Mat bgrChannels[3];

    cv::split(src, bgrChannels);

    for( int i=0; i<3; i++ )
    {
         cv::equalizeHist(bgrChannels[i], bgrChannels[i]);
    }

    cv::Mat out;

    cv::merge(bgrChannels,3,out);

    return out;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString imgPath="../9.jpg"; //9 10
    cv::Mat img = cv::imread( imgPath.toStdString() );

    int exampleNumber=0; // CHANGE TO 1 or 2 or 0 TO SWITCH BETWEEN EXAMPLES 
    if( exampleNumber == 0 ) 
    {
        makeCalcHist(img,true);
    }
    else if( exampleNumber == 1 )
    {
        cv::Mat equalized=makeEqualizeByHist(img,true);
        cv::namedWindow("equalized", cv::WINDOW_AUTOSIZE);
        cv::imshow(     "equalized", equalized);
    } 
    else if( exampleNumber == 2 )
    {
        QString srcPath="../10.jpg";
        QString patternPath="../10_t.jpg";
        cv::Mat src     = cv::imread( srcPath.toStdString() );
        cv::Mat pattern = cv::imread( patternPath.toStdString() );
        // to show pattern uncomment here 
        // cv::imshow(     "src", src);
        // cv::imshow(     "pattern", pattern);

        cv::Mat bproj= makeBackProjection(src,pattern);
        cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
        cv::imshow(     "src", src);
        cv::namedWindow("back_proj", cv::WINDOW_AUTOSIZE);
        cv::imshow(     "back_proj", bproj);
    }

    return a.exec();
}
