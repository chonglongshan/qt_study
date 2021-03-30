QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    paintarea.cpp \
    plugindialog.cpp

HEADERS += \
    mainwindow.h \
    paintarea.h \
    plugindialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#LIBS           = -L../plugins

#macx-xcode {
#    LIBS += -lpnp_basictools$($${QMAKE_XCODE_LIBRARY_SUFFIX_SETTING})
#} else {
#    LIBS += -lpnp_basictools
#    if(!debug_and_release|build_pass):CONFIG(debug, debug|release) {
#        mac:LIBS = $$member(LIBS, 0) $$member(LIBS, 1)_debug
#        win32:LIBS = $$member(LIBS, 0) $$member(LIBS, 1)d
#    }
#}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-qt_subdirs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/temp/test_Plug_and_Paint_Example/plugins/ -lpnp_basictools
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-qt_subdirs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/temp/test_Plug_and_Paint_Example/plugins/ -lpnp_basictoolsd
else:unix: LIBS += -L$$PWD/../../../build-qt_subdirs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/temp/test_Plug_and_Paint_Example/plugins/ -lpnp_basictools

INCLUDEPATH += $$PWD/../../../build-qt_subdirs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/temp/test_Plug_and_Paint_Example/plugins
DEPENDPATH += $$PWD/../../../build-qt_subdirs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/temp/test_Plug_and_Paint_Example/plugins
