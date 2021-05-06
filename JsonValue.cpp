#include"JsonValue.h"
#include"JsonArray.h"
#include"JsonObject.h"
#include<iostream>


JsonValue::JsonValue()
{

}

JsonValue::JsonValue(const JsonValue &other) : valueType(other.type())
{
    if (isBool())
        boolValue = other.boolValue;
    else if (isInt())
        intValue = other.intValue;
    else if (isString())
        stringValue = other.stringValue;
    else if (isObject())
        jsonObjectPtr = std::make_unique<JsonObject>(*other.jsonObjectPtr);
    else if (isArray())
        jsonArrayPtr = std::make_unique<JsonArray>(*other.jsonArrayPtr);
}

JsonValue::JsonValue(bool b) : valueType(Bool), boolValue(b)
{

}

JsonValue::JsonValue(int i) : valueType(Int), intValue(i)
{

}

JsonValue::JsonValue(const std::string &s) : valueType(String), stringValue(s)
{

}

JsonValue::JsonValue(const JsonArray &ja) : valueType(Array)
{
    //jsonArrayPtr = new JsonArray(ja);
    jsonArrayPtr = std::make_unique<JsonArray>(ja);
}

JsonValue::JsonValue(const JsonObject& jo) : valueType(Object)
{
    //jsonObjectPtr = new JsonObject(jo);
    jsonObjectPtr = std::make_unique<JsonObject>(jo);
}


JsonValue &JsonValue::operator=(const JsonValue &other)
{
    clearData();
    valueType = other.type();
    if (isBool())
        boolValue = other.toBool();
    else if (isInt())
        intValue = other.toInt();
    else if (isObject())
        jsonObjectPtr = std::make_unique<JsonObject>(*other.jsonObjectPtr);
    else if (isArray())
        jsonArrayPtr = std::make_unique<JsonArray>(*other.jsonArrayPtr);
    else if (isString())
        stringValue = other.toString();
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
    return isBool() ? boolValue : defaultValue;
}

double JsonValue::toInt(int defaultValue) const
{
    return isInt() ? intValue : defaultValue;
}

std::string JsonValue::toString(const std::string &defaultValue) const
{
    return isString() ? stringValue : defaultValue;
}

JsonArray JsonValue::toArray(const JsonArray &defaultValue) const
{
    return isArray() ? *jsonArrayPtr : defaultValue;
}

JsonObject JsonValue::toObject(const JsonObject &defaultValue) const
{
    return isObject() ? *jsonObjectPtr : defaultValue;
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
        return (boolValue ? "true" : "false");
    else if (isInt())
        return std::to_string(intValue); // << '\n';
    else if (isObject())
        return jsonObjectPtr->getJsonString(space);
    else if (isArray())
        return jsonArrayPtr->getJsonString(space);
    else if (isString()) {
        std::string res = "\"";
        res += stringValue;
        res.push_back('\"');
        return res;
    }
    return "";
}

void JsonValue::clearData()
{
    stringValue.clear();
    jsonArrayPtr.reset();
    jsonObjectPtr.reset();
}

