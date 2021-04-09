#include"JsonParser.h"
#include<iostream>

JsonObject JsonParser::getJsonObject(const std::string &text, size_t &i)
{
    size_t size = text.size();
    JsonObject obj;
    //opening bracket
    while (i < size && isspace(text[i]))
        ++i;
    if (i == size || text[i] != '{')
        return JsonObject();
    //values
    while (i < size && text[i] != '}') {
        ++i;
        //next value "name"
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || text[i++] != '\"')
            return JsonObject();
        size_t j = i + 1;
        while (j < size && text[j] != '\"')
            ++j;
        if (j == size)
            return JsonObject();
        std::string name = text.substr(i, j - i);
        i = j + 1;
        //check for colon beetwen value name and value
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || text[i] != ':')
            return JsonObject();
        ++i;
        //read value
        obj.insert(name, getJsonValue(text, i));

        //check for closing bracket or comma
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || (text[i] != ',' && text[i] != '}'))
            return JsonObject();
    }
    ++i;
    return obj;
}

JsonObject JsonParser::getJsonObject(const std::string &text)
{
    size_t i = 0;
    return getJsonObject(text, i);
}


JsonArray JsonParser::getJsonArray(const std::string &text, size_t &i)
{
    size_t size = text.size();
    JsonArray arr;
    //opening bracket
    while (i < size && isspace(text[i]))
        ++i;
    if (i == size || text[i] != '[')
        return JsonArray();
    //values
    while (i < size && text[i] != ']') {
        ++i;
        arr.pushBack(getJsonValue(text, i));
        //closing bracket or comma
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || (text[i] != ',' && text[i] != ']'))
            return JsonArray();
    }
    ++i;
    return arr;
}

JsonArray JsonParser::getJsonArray(const std::string &text)
{
    size_t i = 0;
    return getJsonArray(text, i);
}

JsonValue JsonParser::getJsonValue(const std::string &text, size_t &i)
{
    size_t size = text.size();
    while (i < size && isspace(text[i]))
        ++i;
    if (i == size)
        return JsonValue();
    //text value
    if (text[i] == '\"') {
        size_t j = i + 1;
        while (j < size && text[j] != '\"')
            ++j;
        if (j == size)
            return JsonValue();
        auto res = JsonValue(text.substr(i + 1, j - i - 1));
        i = j + 1;
        return res;
    }
    //check if value is Json Object or array
    if (text[i] == '{')
        return JsonValue(getJsonObject(text, i));
    if (text[i] == '[')
        return JsonArray(getJsonArray(text, i));
    //read value
    size_t j = i + 1;
    while (j < size && (isalnum(text[j]) || text[j] == '-'))
        ++j;
    std::string val = text.substr(i, j - i);
    i = j;
    //check if value is null
    if (val.compare("null") == 0)
        return JsonValue::getNullValue();
    //check if value is bool
    if (val.compare("true") == 0)
        return JsonValue(true);
    if (val.compare("false") == 0)
        return JsonValue(false);
    //number
    try {
        int n = stoi(val);
        return JsonValue(n);
    }  catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument for Json value: " << ia.what() << '\n';
        return JsonValue();
    }
    //nothing
    return JsonValue();
}
