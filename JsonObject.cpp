#include "JsonObject.h"
#include "JsonParser.h"
#include <iostream>


JsonObject::JsonObject()
{

}

JsonObject::JsonObject(const JsonObject &other) : values(other.values), valsSize(other.size())
{

}

JsonObject &JsonObject::operator=(const JsonObject &other)
{
    values.clear();
    values = other.values;
    valsSize = other.size();
    return *this;
}

JsonObject JsonObject::getFromJsonString(const std::string &json)
{
    return JsonParser::getJsonObject(json);
}

bool JsonObject::isEmpty() const
{
    return values.empty();
}

size_t JsonObject::size() const
{
    return valsSize;
}

JsonValue& JsonObject::get(std::string key)
{
    for (auto iter = values.begin(); iter != values.end(); ++iter) {
        if (iter->first == key)
            return iter->second;
    }
    throw std::out_of_range(key);
}

const JsonValue &JsonObject::get(std::string key) const
{
    for (auto iter = values.begin(); iter != values.end(); ++iter) {
        if (iter->first == key)
            return iter->second;
    }
    throw std::out_of_range(key);
}

void JsonObject::insert(const std::string &key, const JsonValue &value)
{
    values.push_back({key, value});
    ++valsSize;
}

void JsonObject::remove(const std::string &key)
{
    auto iter = find(key);
    if (iter != values.end()) {
        values.erase(iter);
        --valsSize;
    }
}

JsonObject::list::iterator JsonObject::find(std::string key)
{
    for (auto iter = values.begin(); iter != values.end(); ++iter) {
        if (iter->first == key)
            return iter;
    }
    return values.end();
}

JsonObject::list::const_iterator JsonObject::find(std::string key) const
{
    for (auto iter = values.begin(); iter != values.end(); ++iter) {
        if (iter->first == key)
            return iter;
    }
    return values.end();
}

std::string JsonObject::getJsonString(size_t space) const
{
    std::string res;
    std::string fill(space + 4, ' ');
    res += "{\n";
    for (auto iter = values.begin(); iter != values.end(); ++iter) {
        res += fill + "\"" + iter->first + "\" : ";
        res += iter->second.getJsonString(space + 4);
        if (iter != --values.end())
            res += ",\n";
        else
            res.push_back('\n');
    }
    res += std::string(space, ' ') + "}";
    return res;
}

const std::list<std::pair<std::string, JsonValue> > &JsonObject::getValues() const
{
    return values;
}

std::list<std::pair<std::string, JsonValue> > &JsonObject::getValues()
{
    return values;
}


