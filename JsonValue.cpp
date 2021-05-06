#include"JsonValue.h"
#include"JsonArray.h"
#include"JsonObject.h"
#include<iostream>


JsonValue::JsonValue()
{

}

JsonValue::JsonValue(const JsonValue &other)
{
    valueType = other.type();
    if (isNull())
        value = 0;
    else if (isBool())
        value = other.toBool();
    else if (isInt())
        value = other.toInt();
    else if (isObject())
        value = std::make_unique<JsonObject>(other.toObject(JsonObject()));
    else if (isArray())
        value = std::make_unique<JsonArray>(other.toArray(JsonArray()));
    else if (isString())
        value = other.toString();
}

JsonValue::JsonValue(bool b) : value(b), valueType(Bool)
{

}

JsonValue::JsonValue(int i) : value(i), valueType(Int)
{

}

JsonValue::JsonValue(const std::string &s) : value(s), valueType(String)
{

}

JsonValue::JsonValue(const JsonArray &ja) : valueType(Array)
{
    value = std::make_unique<JsonArray>(ja);
}

JsonValue::JsonValue(const JsonObject& jo) : valueType(Object)
{
    value = std::make_unique<JsonObject>(jo);
}


JsonValue &JsonValue::operator=(const JsonValue &other)
{
    valueType = other.type();
    if (isNull())
        value = 0;
    else if (isBool())
        value = other.toBool();
    else if (isInt())
        value = other.toInt();
    else if (isObject())
        value = std::make_unique<JsonObject>(other.toObject(JsonObject()));
    else if (isArray())
        value = std::make_unique<JsonArray>(other.toArray(JsonArray()));
    else if (isString())
        value = other.toString();
    return *this;
}

JsonValue JsonValue::getNullValue()
{
    JsonValue res;
    res.valueType = Null;
    return res;
}

bool JsonValue::isNull() const
{
    return valueType == Null;
}

bool JsonValue::isBool() const
{
    return valueType == Bool;
}

bool JsonValue::isInt() const
{
    return valueType == Int;
}

bool JsonValue::isString() const
{
    return valueType == String;
}

bool JsonValue::isArray() const
{
    return valueType == Array;
}

bool JsonValue::isObject() const
{
    return valueType == Object;
}

bool JsonValue::isUndefined() const
{
    return valueType == Undefined;
}


bool JsonValue::toBool(bool defaultValue) const
{
    return isBool() ? std::get<bool>(value) : defaultValue;
}

int JsonValue::toInt(int defaultValue) const
{
    return isInt() ? std::get<int>(value) : defaultValue;
}

std::string JsonValue::toString(const std::string &defaultValue) const
{
    return isString() ? std::get<std::string>(value) : defaultValue;
}

JsonArray JsonValue::toArray(const JsonArray &defaultValue) const
{
    return isArray() ? *std::get<std::unique_ptr<JsonArray>>(value) : defaultValue;
}

JsonObject JsonValue::toObject(const JsonObject &defaultValue) const
{
    return isObject() ? *std::get<std::unique_ptr<JsonObject>>(value) : defaultValue;
}

JsonValue::Type JsonValue::type() const
{
    return valueType;
}

std::string JsonValue::getJsonString(size_t space) const
{
    if (isUndefined())
        return "";
    if (isNull())
        return "null";
    else if (isBool())
        return (std::get<bool>(value) ? "true" : "false");
    else if (isInt())
        return std::to_string(std::get<int>(value)); // << '\n';
    else if (isObject())
        return std::get<std::unique_ptr<JsonArray>>(value)->getJsonString(space);
    else if (isArray())
        return std::get<std::unique_ptr<JsonArray>>(value)->getJsonString(space);
    else if (isString()) {
        std::string res = "\"";
        res += std::get<std::string>(value);
        res.push_back('\"');
        return res;
    }
    return "";
}

