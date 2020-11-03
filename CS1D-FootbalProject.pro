QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    DisplayInfo.cpp \
    Login.cpp \
    SouvenirAndTrip.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Admin.h \
    DisplayInfo.h \
    Header.h \
    Login.h \
    SouvenirAndTrip.h \
    mainwindow.h

FORMS += \
    Admin.ui \
    DisplayInfo.ui \
    Login.ui \
    SouvenirAndTrip.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    BackgroundImages.qrc