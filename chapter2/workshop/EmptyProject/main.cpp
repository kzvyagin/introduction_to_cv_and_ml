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

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString imgPath="../EmptyProject/1.png";
     auto t1 = std::chrono::high_resolution_clock::now();

    cv::Mat img = cv::imread( imgPath.toStdString() );

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    qDebug() << ms_double.count() << "ms";

    cv::namedWindow(imgPath.toStdString(), cv::WINDOW_AUTOSIZE);
    cv::imshow(imgPath.toStdString(), img);
    cv::waitKey();

    return 0;
}
