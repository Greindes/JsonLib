#include"JsonArray.h"
#include"JsonParser.h"
#include<iostream>


JsonArray::JsonArray()
{

}

JsonArray JsonArray::getFromJsonString(const std::string &json)
{
    return JsonParser::getJsonArray(json);
}

size_t JsonArray::size()
{
    return values.size();
}

void JsonArray::pushBack(const JsonValue &value)
{
    values.push_back(value);
}

void JsonArray::popBack()
{
    values.pop_back();
}

void JsonArray::clear()
{
    values.clear();
}

const JsonValue &JsonArray::operator[](size_t i) const
{
    return values[i];
}

std::string JsonArray::getJsonString(size_t space) const
{
    std::string res(1, '[');
    size_t size = values.size();
    for (size_t i = 0; i < size; ++i) {
        res += values[i].getJsonString(space);
        if (i < size - 1)
            res += ", ";
    }
    res += "]\n";
    return res;
}

void JsonArray::print(size_t space) const
{
    size_t size = values.size();
    std::cout << '[';
    for (size_t i = 0; i < size; ++i) {
        values[i].print(space);
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";
}

JsonValue &JsonArray::operator[](size_t i)
{
    return values[i];
}
