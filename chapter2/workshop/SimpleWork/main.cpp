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


void drawGrid( cv::Mat &img){
    for (int i = 0; i < img.rows; i++)
    for (int j = 0; j < img.cols; j++)
        if ((i % 20 == 10 && j % 2 == 1) ||                        (j % 50 == 25 && i % 2 == 1))                {
    img.at<cv::Vec3b>(i, j)[0] = 255;
    img.at<cv::Vec3b>(i, j)[1] = 255;
    img.at<cv::Vec3b>(i, j)[2] = 255;
     }
}

void recolorColor(cv::Mat &img)
{
    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
    if (     img.at<cv::Vec3b>(i, j)[0] > 220
          && img.at<cv::Vec3b>(i, j)[2] > 220
          && img.at<cv::Vec3b>(i, j)[1] > 220 )
       {
           img.at<cv::Vec3b>(i, j)[0] = 0;
           img.at<cv::Vec3b>(i, j)[1] = 0;
           img.at<cv::Vec3b>(i, j)[2] = 255;
       }
}


void drawRectAndShowWithSource(cv::Mat imgSrg)
{
    cv::Mat img;
    imgSrg.copyTo(img); // deep copy
    qDebug()<<"pringing cols, rows, type: "<<img.cols << img.rows << img.type();

    cv::Mat mat3 ( cv::Size(img.cols, img.rows), img.type() );
    mat3.setTo(cv::Scalar(0,0,0));
    cv::rectangle(mat3,cv::Rect(100,100,100,100),cv::Scalar(0,0,255),3);

    cv::namedWindow("RECT1", cv::WINDOW_AUTOSIZE);
    cv::imshow("RECT1", mat3    );
    cv::Mat img2;
    cv::addWeighted( img, 1, mat3, 1, 0.0, img2);
    cv::namedWindow("Display window5", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window5", img2);
}



void resizeImage(cv::Mat source)
{
    cv::Mat dst;
    // You can try more different parameters
    cv::resize(source, dst, cv::Size(300, 300), 0, 0, cv::INTER_AREA);
    cv::imshow("canvasOutput",dst );
    cv::imshow("canvasInput",source );
    while(cv::waitKey(1) != 27); // 27 = ascii value of ESC
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



    QString imgPath="5.jpg";
    cv::Mat img = cv::imread( imgPath.toStdString() );

    qDebug()<<"Channels:"<<img.channels()<<" Type:"<<img.type();

    cv::Mat img2;
    img.copyTo(img2);

/* uncommetn section to test recolor color function
      {
        recolorColor(img);
        cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display window", img);
    }
*/

    {
        drawGrid(img2);
        cv::namedWindow("Display window2", cv::WINDOW_AUTOSIZE);
        cv::imshow("Display window2", img2);
    }

/* uncomment section to test resizing image
    {
        resizeImage(img);
    }
*/

    drawRectAndShowWithSource(img);

    cv::namedWindow("Display window3", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window3", img2*2);





    return a.exec();
}
