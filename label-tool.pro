QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Application.cpp \
    canvas.cpp \
    fileView.cpp \
    labelDialog.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp \
    shape.cpp

HEADERS += \
    Application.h \
    canvas.h \
    commenFunction.h \
    fileView.h \
    labelDialog.h \
    mainwindow.h \
    settings.h \
    settings.h \
    shape.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




HEADERS += \
    canvas.h \
    commenFunction.h \
    mainwindow.h \
    settings.h \
    shape.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    asset.qrc

TRANSLATIONS += \
    label_tool_zh_CN.ts

DISTFILES +=


