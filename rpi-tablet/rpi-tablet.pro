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
SOURCES += window/windowbanner.cpp
SOURCES += window/windownavbar.cpp
SOURCES += pages/pagehome.cpp
SOURCES += pages/pagemusic.cpp
SOURCES += pages/pageweather.cpp
SOURCES += pages/pagesettings.cpp

HEADERS += mainwindow.h
HEADERS += window/windowbanner.h
HEADERS += window/windownavbar.h
HEADERS += pages/pagehome.h
HEADERS += pages/pagemusic.h
HEADERS += pages/pageweather.h
HEADERS += pages/pagesettings.h


RESOURCES += assets/assets.qrc
