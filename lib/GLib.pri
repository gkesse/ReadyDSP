include(view/GView.pri)

INCLUDEPATH += \
    $$PWD

SOURCES += \
    $$PWD/GSignal.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GGlobal.cpp \
    $$PWD/GAverage.cpp \
    $$PWD/GMinMax.cpp \
    $$PWD/GFourier.cpp \
    $$PWD/GSampling.cpp \
    $$PWD/GIntegrate.cpp \
    $$PWD/GInterPol.cpp

HEADERS += \
    $$PWD/GSignal.h \
    $$PWD/GStyle.h \
    $$PWD/GGlobal.h \
    $$PWD/GAverage.h \
    $$PWD/GMinMax.h \
    $$PWD/GFourier.h \
    $$PWD/GSampling.h \
    $$PWD/GInterPol.h \
    $$PWD/GIntegrate.h

RESOURCES += \
    $$PWD/resource.qrc

