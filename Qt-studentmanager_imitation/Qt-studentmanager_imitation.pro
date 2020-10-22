QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allstuinform.cpp \
    globle.cpp \
    main.cpp \
    mainwindow.cpp \
    manger.cpp \
    studentform.cpp

HEADERS += \
    allstuinform.h \
    globle.h \
    mainwindow.h \
    manger.h \
    studentform.h

FORMS += \
    allstuinform.ui \
    mainwindow.ui \
    manger.ui \
    studentform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += sql
