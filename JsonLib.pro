CONFIG -= qt

TEMPLATE = lib
DEFINES += JSONLIB_LIBRARY

CONFIG += c++11 c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    JsonArray.cpp \
    JsonObject.cpp \
    JsonParser.cpp \
    JsonValue.cpp

HEADERS += \
    JsonArray.h \
    JsonLib_global.h \
    JsonObject.h \
    JsonParser.h \
    JsonValue.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
