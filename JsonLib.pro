TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        JsonObject.cpp \
        JsonValue.cpp \
        main.cpp

HEADERS += \
    JsonObject.h \
    JsonValue.h
