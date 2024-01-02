QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

#Attention ! Change  "INCLUDEPATH" and "LIBS += -L" to you opencv path in you system. 
INCLUDEPATH += /home/student/cv/cv/include/opencv4/
#/usr/include/opencv

LIBS+= -L/home/student/cv/cv/lib/


LIBS += -lopencv_features2d
LIBS += -lopencv_videoio
LIBS += -lopencv_video
LIBS += -lopencv_imgproc
LIBS += -lopencv_photo
LIBS += -lopencv_objdetect
LIBS += -lopencv_ml
LIBS += -lopencv_gapi
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_calib3d
LIBS += -lopencv_stitching
LIBS += -lopencv_dnn
LIBS += -lopencv_flann


SOURCES += \
        main.cpp
