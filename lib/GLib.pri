include(view/GView.pri)

INCLUDEPATH += \
    $$PWD

SOURCES += \
    $$PWD/GSignal.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GGlobal.cpp

HEADERS += \
    $$PWD/GSignal.h \
    $$PWD/GStyle.h \
    $$PWD/GGlobal.h

RESOURCES += \
    $$PWD/resource.qrc

