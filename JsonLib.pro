TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        JsonArray.cpp \
        JsonObject.cpp \
        JsonValue.cpp \
        main.cpp

HEADERS += \
    JsonArray.h \
    JsonObject.h \
    JsonValue.h
