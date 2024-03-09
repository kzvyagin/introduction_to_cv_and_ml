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
#include <QFileInfo>
#include <QDebug>

void detectRussinPlate()
{
    QString russianPlateModelPath="haarcascade_russian_plate_number.xml";
    QString imgPath="2.jpg"; // plates
    if(     !QFileInfo::exists(russianPlateModelPath) )
    {
        qDebug()<< "ERROR File 'haarcascade_russian_plate_number.xml' dosent exists";
        return ;
    }

    if(!QFileInfo::exists(imgPath) )
    {
        qDebug()<< "ERROR File '2.jpg' dosent exists";
        return ;
    }

    cv::CascadeClassifier m_platesClassifier;
    m_platesClassifier.load( russianPlateModelPath.toStdString() );

    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat gray;
    cv::cvtColor( img, gray, cv::COLOR_BGR2GRAY );
    std::vector< cv::Rect >     plates;
    std::vector< int      >    numDetections; // это количество соседних положительно классифицированных прямоугольников, которые были соединены вместе, чтобы сформировать объект
     // чем выше это значение, тем выше вероятность того что прямоугольник с таким-же индектом из plates являеться номером

    m_platesClassifier.detectMultiScale( gray,
                                         plates ,
                                         numDetections  );


    // printing
    qDebug()<< "plates.count:" << plates.size();

    qDebug()<<"numDetections:" <<numDetections;
    int i=0;
    foreach( const cv::Rect& r, plates )
    {
         qDebug()<<"square:" <<r.width*r.height<<" objects:"<<numDetections[i++];
    }


    QPixmap pix( imgPath );
    QPainter painter;
    painter.begin( &pix );
    painter.setPen( Qt::green );


    foreach( const cv::Rect& r, plates )
    {
        painter.drawRect( r.x, r.y, r.width, r.height );
    }

    painter.end();


    QLabel *label=new QLabel();
    label->setGeometry( QRect(100,100,pix.size().width(),pix.size().height()));
    label->show();
    label->setPixmap(pix);

}

void detectFaces()
{
    QString facesPath="../cv/share/opencv4/haarcascades/haarcascade_frontalface_default.xml";
    QFileInfo info(facesPath);
    if( !info.exists() )
    {
        qDebug()<< "ERROR File 'haarcascade_frontalface_default.xml' dosent exists";
        return ;
    }
    cv::CascadeClassifier m_faceClassifier;
    m_faceClassifier.load( facesPath.toStdString() );

    QString imgPath="../1.jpg"; // faces
    cv::Mat img = cv::imread( imgPath.toStdString() );
    cv::Mat gray;
    cv::cvtColor( img, gray, cv::COLOR_BGR2GRAY );
    std::vector< cv::Rect > faces;
    m_faceClassifier.detectMultiScale( gray, faces );


    QPixmap pix( imgPath );
    QPainter painter;
    painter.begin( &pix );
    painter.setPen( Qt::green );
    foreach( const cv::Rect& r, faces )
    {
        painter.drawRect( r.x, r.y, r.width, r.height );
    }

    painter.end();


    QLabel *label= new QLabel();
    label->setGeometry( QRect(100,100,pix.size().width(),pix.size().height()));
    label->show();
    label->setPixmap(pix);

}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    detectRussinPlate();

    return a.exec();
}
