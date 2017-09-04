include(view/GView.pri)

INCLUDEPATH += \
    $$PWD

SOURCES += \
    $$PWD/GSignal.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GGlobal.cpp \
    $$PWD/GAverage.cpp \
    $$PWD/GMinMax.cpp

HEADERS += \
    $$PWD/GSignal.h \
    $$PWD/GStyle.h \
    $$PWD/GGlobal.h \
    $$PWD/GAverage.h \
    $$PWD/GMinMax.h

RESOURCES += \
    $$PWD/resource.qrc

