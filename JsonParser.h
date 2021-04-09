#ifndef JSONPARSER_H
#define JSONPARSER_H

#include"JsonObject.h"
#include"JsonArray.h"
#include"JsonValue.h"


namespace JsonParser {
    JsonObject getJsonObject(const std::string & text, size_t & i);
    JsonObject getJsonObject(const std::string & text);

    JsonArray getJsonArray(const std::string & text, size_t & i);
    JsonArray getJsonArray(const std::string & text);

    JsonValue getJsonValue(const std::string& text, size_t & i);
}

#endif // JSONPARSER_H
