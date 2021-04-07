TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        JsonArray.cpp \
        JsonObject.cpp \
        JsonParser.cpp \
        JsonValue.cpp \
        main.cpp

HEADERS += \
    JsonArray.h \
    JsonObject.h \
    JsonParser.h \
    JsonValue.h
