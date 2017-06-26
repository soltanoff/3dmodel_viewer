QT += core gui 3dcore 3drender 3dinput 3dquick qml quick 3dquickextras 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModelViewer
TEMPLATE = app

SOURCES += main.cpp \
    scenewalker.cpp \
    sceneviewer.cpp \
    maindialog.cpp \
    viewsettings.cpp

HEADERS += \
    scenewalker.h \
    sceneviewer.h \
    maindialog.h \
    viewsettings.h

FORMS += \
    maindialog.ui
