#ifndef JSONPARSER_H
#define JSONPARSER_H

#include"JsonLib_global.h"
#include"JsonObject.h"
#include"JsonArray.h"
#include"JsonValue.h"


namespace JsonParser {
    JsonObject JSONLIB_EXPORT getJsonObject(const std::string & text, size_t & i);
    JsonObject JSONLIB_EXPORT getJsonObject(const std::string & text);

    JsonArray JSONLIB_EXPORT getJsonArray(const std::string & text, size_t & i);
    JsonArray JSONLIB_EXPORT getJsonArray(const std::string & text);

    JsonValue JSONLIB_EXPORT getJsonValue(const std::string& text, size_t & i);
}

#endif // JSONPARSER_H
