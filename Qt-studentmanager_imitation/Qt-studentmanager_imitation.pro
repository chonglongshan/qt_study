QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allstuinform.cpp \
    awardfind.cpp \
    coursefind.cpp \
    dormfind.cpp \
    findclass.cpp \
    findscore.cpp \
    globle.cpp \
    insertlogin.cpp \
    main.cpp \
    mainwindow.cpp \
    manger.cpp \
    moneyfind.cpp \
    studentform.cpp \
    userlogin.cpp

HEADERS += \
    allstuinform.h \
    awardfind.h \
    coursefind.h \
    dormfind.h \
    findclass.h \
    findscore.h \
    globle.h \
    insertlogin.h \
    mainwindow.h \
    manger.h \
    moneyfind.h \
    studentform.h \
    userlogin.h

FORMS += \
    allstuinform.ui \
    awardfind.ui \
    coursefind.ui \
    dormfind.ui \
    findclass.ui \
    findscore.ui \
    insertlogin.ui \
    mainwindow.ui \
    manger.ui \
    moneyfind.ui \
    studentform.ui \
    userlogin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += sql
