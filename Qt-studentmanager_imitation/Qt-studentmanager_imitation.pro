QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allstuinform.cpp \
    awardfind.cpp \
    awardmanage.cpp \
    classmanage.cpp \
    coursefind.cpp \
    coursemanage.cpp \
    deletelogin.cpp \
    dormfind.cpp \
    dormmanage.cpp \
    feemanage.cpp \
    findclass.cpp \
    findscore.cpp \
    globle.cpp \
    insertlogin.cpp \
    main.cpp \
    mainwindow.cpp \
    manger.cpp \
    moneyfind.cpp \
    scoremanage.cpp \
    seeallstuinfor.cpp \
    seedorminfor.cpp \
    student.cpp \
    studentform.cpp \
    stuinformanage.cpp \
    updatelogin.cpp \
    userlogin.cpp

HEADERS += \
    allstuinform.h \
    awardfind.h \
    awardmanage.h \
    classmanage.h \
    coursefind.h \
    coursemanage.h \
    deletelogin.h \
    dormfind.h \
    dormmanage.h \
    feemanage.h \
    findclass.h \
    findscore.h \
    globle.h \
    insertlogin.h \
    mainwindow.h \
    manger.h \
    moneyfind.h \
    scoremanage.h \
    seeallstuinfor.h \
    seedorminfor.h \
    student.h \
    studentform.h \
    stuinformanage.h \
    updatelogin.h \
    userlogin.h

FORMS += \
    allstuinform.ui \
    awardfind.ui \
    awardmanage.ui \
    classmanage.ui \
    coursefind.ui \
    coursemanage.ui \
    deletelogin.ui \
    dormfind.ui \
    dormmanage.ui \
    feemanage.ui \
    findclass.ui \
    findscore.ui \
    insertlogin.ui \
    mainwindow.ui \
    manger.ui \
    moneyfind.ui \
    scoremanage.ui \
    seeallstuinfor.ui \
    seedorminfor.ui \
    studentform.ui \
    stuinformanage.ui \
    updatelogin.ui \
    userlogin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += sql

SUBDIRS += \
    studenntManger.pro
