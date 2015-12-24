TARGET = plugin1
TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../app1

SOURCES += plugin1.cpp \
    form.cpp

HEADERS += plugin1.h \
    form.h

FORMS += \
    form.ui
