#-------------------------------------------------
#
# Project created by QtCreator 2019-08-05T22:08:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Omok-Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
INCLUDEPATH += C:/boost_1_68_0/

LIBS += "-LC:/boost_1_68_0/stage/lib/"


SOURCES += \
        computerplayer.cpp \
        gamemanager.cpp \
        gamescene.cpp \
        humanplayer.cpp \
        main.cpp \
        mainwindow.cpp \
        player.cpp \
        resourcemanager.cpp

HEADERS += \
        computerplayer.h \
        constant.h \
        gamemanager.h \
        gamescene.h \
        humanplayer.h \
        mainwindow.h \
        player.h \
        resourcemanager.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
win32:RC_ICONS += resource/img/icon.ico
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
