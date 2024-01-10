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

#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

Point pt1, pt2;
int state;
bool flag, ready;

// Функция обратного вызова щелчка левой кнопкой мыши, используется для возврата координат щелчка
void mouseCaller(int event, int x, int y, int flags, void* data) {
    Point* pt = reinterpret_cast<Point*>(data);
    switch (event) {
        case EVENT_LBUTTONDOWN: {
            *pt = Point(x, y);
            flag = true;
        } break;
    }
}

int main() {
    namedWindow("Input", WINDOW_AUTOSIZE);
    namedWindow("ROI", WINDOW_AUTOSIZE);
    namedWindow("backProj", WINDOW_AUTOSIZE);

    Mat img = imread("../RHist/5.jpg"); // Устанавливаем соответствующий путь к изображению
    if (img.empty()) { cout << "Error: read image fails!\n"; return -1; }
    imshow("Input", img);

    // Получаем гистограмму исходного изображения (не обязательно)
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    int hbins = 30, sbins = 32;
    int histSize[] = { hbins, sbins };
    float hranges[] = { 0, 180 };
    float sranges[] = { 0, 256 };
    const float* ranges[] = { hranges, sranges };
    MatND hist;
    int channels[] = { 0, 1 };
    calcHist(&hsv, 1, channels, Mat(), hist, 2, histSize, ranges, true, false);


    // Получаем кнопку мыши и генерируем подходящую область ROI
    state = 0;
    flag = false;
    ready = false;
    Point pos;
    setMouseCallback("Input", mouseCaller, &pos);
    while (true){
        
        if (27 == waitKey(1)) 
            break; // клавиша Esc для выхода
        
        if (flag) {
            switch (state) {
                case 0:
                {
                    pt1 = pos;
                    state = 1;
                    flag = false;
                    cout << "enter state 0 \n";
                    break;
                }
                case 1:
                {
                    pt2 = pos;
                    state = 0;
                    flag = false;
                    cout << "enter state 1 \n";
                    rectangle(img, Rect(pt1, pt2), Scalar(0, 0, 0xff), 1);
                    imshow("Input", img);
                    ready = true;
                    break;
                }
            }
        }
        if (ready) { // Процесс создания обратной проекции
            cout << "enter ready state \n";
            Mat roi = hsv(Rect(pt1,pt2));
            imshow("ROI", roi);
            Mat roiHist;
            calcHist(&roi, 1, channels, Mat(), roiHist, 2, histSize, ranges, true, false);
            normalize(roiHist, roiHist, 0, 255, NORM_MINMAX, -1,Mat());
            Mat backProjImg;
            calcBackProject(&hsv, 1, channels, roiHist, backProjImg, ranges, 1, true);
            imshow("backProj", backProjImg);
            ready = false;
        }
    }

    destroyAllWindows();
    return 0;
}


