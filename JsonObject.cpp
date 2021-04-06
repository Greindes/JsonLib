#include "JsonObject.h"
#include <iostream>


JsonObject::JsonObject()
{

}

bool JsonObject::isEmpty()
{
    return values.empty();
}

size_t JsonObject::size()
{
    return valsSize;
}

JsonValue JsonObject::get(std::string key)
{
    for (auto iter = begin(); iter != end(); ++iter) {
        if (iter.key() == key)
            return iter.value();
    }
    return JsonValue();
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

void JsonObject::print(size_t tab) const
{
    std::string fill(tab + 4, ' ');
    std::cout << "{\n";
    for (const auto & ptr : values) {
        std::cout << fill << '\"' << ptr.first << "\" : ";
        ptr.second.print(tab + 4);
    }
    std::cout << std::string(tab, ' ') << "}\n";
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
