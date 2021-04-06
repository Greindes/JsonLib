#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <fstream>
#include <streambuf>
#include "JsonObject.h"
#include "JsonValue.h"
#include "JsonArray.h"


JsonObject getJsonObject(const std::string & text, size_t & i);
JsonArray getJsonArray(const std::string & text, size_t & i);

JsonValue getJsonValue(const std::string& text, size_t & i) {
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
    //OBJECT AND ARRAY
    if (text[i] == '{')
        return JsonValue(getJsonObject(text, i));
    if (text[i] == '[')
        return JsonArray(getJsonArray(text, i));
    size_t j = i + 1;
    while (j < size && (isalnum(text[j]) || text[j] == '-'))
        ++j;
    std::string val = text.substr(i, j - i);
    i = j;
    //bool
    if (val.compare("true") == 0)
        return JsonValue(true);
    if (val.compare("false") == 0)
        return JsonValue(false);
    //num
    try {
        int n = stoi(val);
        return JsonValue(n);
    }  catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return JsonValue();
    }
    //nothing
    return JsonValue();
}


JsonObject getJsonObject(const std::string & text, size_t & i) {
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
        //next value name
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
        //colon
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || text[i] != ':')
            return JsonObject();
        ++i;
        obj.insert(name, getJsonValue(text, i));

        //closing bracket or comma
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || (text[i] != ',' && text[i] != '}'))
            return JsonObject();
    }
    ++i;
    return obj;
}

JsonArray getJsonArray(const std::string & text, size_t & i) {
    size_t size = text.size();
    JsonArray arr;
    //opening bracket
    while (i < size && isspace(text[i]))
        ++i;
    if (i == size || text[i] != '[')
        return JsonArray();
    //values
    while (i < size && text[i] != ']') {
        std::cout << text[i] << ' ' << text[i + 1] << '\n';
        ++i;
        arr.pushBack(getJsonValue(text, i));
        std::cout << arr[arr.size() - 1].type() << '\n';
        //closing bracket or comma
        while (i < size && isspace(text[i]))
            ++i;
        if (i == size || (text[i] != ',' && text[i] != ']'))
            return JsonArray();
    }
    ++i;
    return arr;
}


int main()
{
    std::ifstream t("D:/CPP/build-JsonLib-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/txt.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    size_t i = 0;
    auto obj = getJsonObject(str, i);
    obj.print();
    return 0;
}
