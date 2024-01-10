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


cv::Mat my_dilation(cv::Mat img,
                 int dilation_elem = 0, // вид ядра
                 int dilation_size = 0  // размер ядра
                )
{
    int dilation_type = 0;

    if( dilation_elem == 0 )
    {
        dilation_type = cv::MORPH_RECT;
    }
    else if( dilation_elem == 1 )
    {
        dilation_type = cv::MORPH_CROSS;
    }
    else if( dilation_elem == 2)
    {
        dilation_type = cv::MORPH_ELLIPSE;
    }
    cv::Mat kernel = cv::getStructuringElement( dilation_type,
                         cv::Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                         cv::Point( dilation_size, dilation_size ) );
    cv::Mat out;
    cv::dilate( img, out, kernel );
    return out;
}

cv::Mat  my_erosion( cv::Mat img,
              int erosion_elem =0,// вид ядра
              int erosion_size=0 // размер ядра
        )
{
  int erosion_type = 0;
  if( erosion_elem == 0 )
  {
      erosion_type = cv::MORPH_RECT;
  }
  else if( erosion_elem == 1 )
  {
      erosion_type = cv::MORPH_CROSS;
  }
  else if( erosion_elem == 2)
  {
      erosion_type = cv::MORPH_ELLIPSE;
  }

  cv::Mat kernel = cv::getStructuringElement( erosion_type,
                       cv::Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       cv::Point( erosion_size, erosion_size ) );
  cv::Mat out;
  cv::erode( img, out, kernel );
  return out;

}

cv::Mat  my_morphologyEx( cv::Mat img,
                         cv::MorphTypes type, // тип морфологии
              int erosion_elem =0,// вид ядра
              int erosion_size=0 // размер ядра
        )
{
  int erosion_type = 0;
  if( erosion_elem == 0 )
  {
      erosion_type = cv::MORPH_RECT;
  }
  else if( erosion_elem == 1 )
  {
      erosion_type = cv::MORPH_CROSS;
  }
  else if( erosion_elem == 2)
  {
      erosion_type = cv::MORPH_ELLIPSE;
  }

  cv::Mat kernel = cv::getStructuringElement( erosion_type,
                       cv::Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       cv::Point( erosion_size, erosion_size ) );
  cv::Mat out;
  cv::morphologyEx(img,out, type, kernel);
  return out;

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath="../MorphologicalTransforms/6.png";
    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat out;
    auto t1 = std::chrono::high_resolution_clock::now();



    out=my_erosion ( img, 0  ,3);
    out=my_dilation( out, 0 ,3);
  // out=my_morphologyEx( img, cv::MORPH_BLACKHAT, 0 ,3);



    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    qDebug() << ms_double.count() << "ms";

    cv::namedWindow(imgPath.toStdString(), cv::WINDOW_AUTOSIZE);
    cv::imshow(imgPath.toStdString(), out);

    return a.exec();
}
