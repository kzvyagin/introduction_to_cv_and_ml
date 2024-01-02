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


cv::Mat makeBorder(cv::Mat img, int borderType, int borderWidth=10)
{

    int top(borderWidth), bottom(borderWidth), left(borderWidth), right(borderWidth);

    cv::Scalar value(  255,  255,  0 );
    cv::Mat out;
    cv::copyMakeBorder( img, out, top, bottom, left, right, borderType, value );

    return out;
}

cv::Mat makeBlur(cv::Mat img, cv::Size size)
{
    cv::Mat out;
    cv::blur(img, out, size );

    return out;
}


cv::Mat makeBoxFilter(cv::Mat img, cv::Size size)
{
    cv::Mat out;
    cv::boxFilter(img, out,-1, size );

    return out;
}

cv::Mat makeCustomFilter(cv::Mat img)
{
// Creating kernel matrix
    int kernel_size=30;
    cv::Mat kernel =cv::Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);


     cv::Mat out;
     cv::filter2D(img, out, -1, kernel);
     return out;
}
// size должен быть не четным
cv::Mat makeGussianBlur(cv::Mat img, cv::Size size)
{
    cv::Mat out;
    cv::GaussianBlur(img, out, size ,0,0);

    return out;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath="../Filters/7.jpeg";
    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat out;
    auto t1 = std::chrono::high_resolution_clock::now();



    //makeBorder(img, cv::BORDER_REPLICATE);//BORDER_CONSTANT;

    //out=makeBlur(img,cv::Size(30,30));

    //out=makeBoxFilter( img, cv::Size(30,30) );

    //out=makeGussianBlur( img, cv::Size(31,31) );

    out=makeCustomFilter(img);

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    qDebug() << ms_double.count() << "ms";

    cv::namedWindow(imgPath.toStdString(), cv::WINDOW_AUTOSIZE);
    cv::imshow(imgPath.toStdString(), out);

    return a.exec();
}
