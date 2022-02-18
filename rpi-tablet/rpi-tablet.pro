DEFINES += QT_NO_NARROWING_CONVERSIONS_IN_CONNECT
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11


QT += core
QT += gui
QT += widgets
QT += multimedia


SOURCES += main.cpp
SOURCES += mainwindow.cpp
SOURCES += frames/framenavbar.cpp
SOURCES += frames/framehome.cpp
SOURCES += frames/framemusic.cpp
SOURCES += frames/frameweather.cpp
SOURCES += frames/framesettings.cpp

HEADERS += mainwindow.h
HEADERS += frames/framenavbar.h
HEADERS += frames/framehome.h
HEADERS += frames/framemusic.h
HEADERS += frames/frameweather.h
HEADERS += frames/framesettings.h


RESOURCES += assets/assets.qrc
