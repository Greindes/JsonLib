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
        jsonObjectPtr = new JsonObject(*other.jsonObjectPtr);
    else if (isArray())
        jsonArrayPtr = new JsonArray(*other.jsonArrayPtr);
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
    jsonArrayPtr = new JsonArray(ja);
}

JsonValue::JsonValue(const JsonObject& jo) : valueType(Object)
{
    jsonObjectPtr = new JsonObject(jo);
}

JsonValue::~JsonValue()
{
    if (jsonArrayPtr)
        delete jsonArrayPtr;
    if (jsonObjectPtr)
        delete jsonObjectPtr;
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

void JsonValue::print(size_t tab) const
{
    if (isUndefined())
        return;
    if (isBool())
        std::cout << (boolValue ? "true" : "false") << '\n';
    else if (isInt())
        std::cout << intValue << '\n';
    else if (isString())
        std::cout << '\"' << stringValue << "\"\n";
    else if (isObject())
        jsonObjectPtr->print(tab);
    else if (isArray())
        jsonArrayPtr->print(tab);
}
