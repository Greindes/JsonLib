#include "JsonValue.h"


JsonValue::JsonValue()
{

}

JsonValue::JsonValue(bool b) : valueType(Bool), boolValue(b)
{

}

JsonValue::JsonValue(double d) : valueType(Double), doubleValue(d)
{

}

JsonValue::JsonValue(const std::string &s) : valueType(String), stringValue(s)
{

}
/*
JsonValue::JsonValue(const JsonObject& jo) : valueType(Object), jsonObjectPtr(new JsonObject(jo))
{

}*/

bool JsonValue::isNull() const
{
    return valueType == Null;
}

bool JsonValue::isBool() const
{
    return valueType == Bool;
}

bool JsonValue::isDouble() const
{
    return valueType == Double;
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

double JsonValue::toDouble(double defaultValue) const
{
    return isDouble() ? doubleValue : defaultValue;
}

std::string JsonValue::toString(const std::string &defaultValue) const
{
    return isString() ? stringValue : defaultValue;
}

/*JsonObject JsonValue::toObject(const JsonObject &defaultValue) const
{
    return *jsonObjectPtr;
}*/

JsonValue::Type JsonValue::type() const
{
    return valueType;
}
