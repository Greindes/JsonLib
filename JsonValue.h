#ifndef JSONVALUE_H
#define JSONVALUE_H

#include<string>
#include<memory>
#include"JsonObject.h"

class JsonValue
{
public:
    enum Type { Null, Bool, Double, String, Array, Object, Undefined };
    JsonValue();
    JsonValue(bool b);
    JsonValue(double d);
    JsonValue(const std::string& s);
    //JsonValue(JsonArray);
    JsonValue(const JsonObject& jo);

    bool isNull() const;
    bool isBool() const;
    bool isDouble() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;
    bool isUndefined() const;

    bool toBool(bool defaultValue = false) const;
    double toDouble(double defaultValue = 0.0) const;
    std::string toString(const std::string& defaultValue = "") const;
    //bool toArray(const JsonArray& defaultValue = JsonArray()) const
    JsonObject toObject(const JsonObject& defaultValue = JsonObject()) const;

    Type type() const;

private:
    Type valueType = Null;
    bool boolValue;
    double doubleValue;
    std::string stringValue;
    //std::unique_ptr<JsonArray> jsonArrayPtr;
    std::unique_ptr<JsonObject> jsonObjectPtr;

};

#endif // JSONVALUE_H
