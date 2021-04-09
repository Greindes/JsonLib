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
    for (auto iter = begin(); iter != end(); ++iter) {
        if (iter.key() == key)
            return *iter;
    }
    throw std::out_of_range(key);
}

JsonObject::iterator JsonObject::find(std::string key)
{
    for (auto iter = begin(); iter != end(); ++iter) {
        if (iter.key() == key)
            return iter;
    }
    return end();
}

JsonObject::iterator JsonObject::begin()
{
    iterator res;
    res.iter = values.begin();
    return res;
}

JsonObject::iterator JsonObject::end()
{
    iterator res;
    res.iter = values.end();
    return res;
}

void JsonObject::insert(const std::string &key, const JsonValue &value)
{
    values.push_back({key, value});
    ++valsSize;
}

void JsonObject::remove(const std::string &key)
{
    auto iter = find(key);
    if (iter != end()) {
        values.erase(iter.iter);
        --valsSize;
    }
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


JsonObject::iterator::iterator()
{

}

JsonObject::iterator::iterator(const JsonObject::iterator &other) : iter(other.iter)
{

}

std::string JsonObject::iterator::key() const
{
    return iter->first;
}

JsonValue JsonObject::iterator::value() const
{
    return iter->second;
}

JsonObject::iterator JsonObject::iterator::operator++()
{
    ++iter;
    return *this;
}

JsonObject::iterator JsonObject::iterator::operator--()
{
    --iter;
    return *this;
}

JsonValue &JsonObject::iterator::operator*() const
{
    return iter->second;
}

bool JsonObject::iterator::operator==(const JsonObject::iterator &other) const
{
    return iter == other.iter;
}

bool JsonObject::iterator::operator!=(const JsonObject::iterator &other) const
{
    return iter != other.iter;
}
