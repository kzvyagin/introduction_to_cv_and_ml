#***************************************
# Copyright (c) 2024 Konstantin Zvyagin.
# e-mail: knzvyagin@gmail.com
# SPDX-License-Identifier: BSD-3-Clause	
#***************************************

QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

#Attention ! Change  "INCLUDEPATH" and "LIBS += -L" to you opencv path in you system.
INCLUDEPATH += /usr/include/opencv4/
LIBS+= -L/usr/lib/aarch64-linux-gnu/

LIBS+= -L../cv/lib/

LIBS += -lopencv_features2d
LIBS += -lopencv_videoio
LIBS += -lopencv_video
LIBS += -lopencv_imgproc
LIBS += -lopencv_photo
LIBS += -lopencv_objdetect
LIBS += -lopencv_ml
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_calib3d
LIBS += -lopencv_stitching
LIBS += -lopencv_dnn
LIBS += -lopencv_flann



SOURCES += \
        main.cpp
