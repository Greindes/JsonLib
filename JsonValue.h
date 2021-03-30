#ifndef JSONVALUE_H
#define JSONVALUE_H

#include<string>

class JsonObject;
class JsonArray;

class JsonValue
{
public:
    enum Type { Null, Bool, Double, String, Array, Object, Undefined };
    JsonValue();
    JsonValue(bool b);
    JsonValue(double d);
    JsonValue(const std::string& s);
    JsonValue(const JsonArray& ja);
    JsonValue(const JsonObject& jo);
    ~JsonValue();

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
    JsonArray toArray(const JsonArray& defaultValue) const;
    JsonObject toObject(const JsonObject& defaultValue) const;

    Type type() const;

private:
    Type valueType = Null;
    bool boolValue;
    double doubleValue;
    std::string stringValue;
    JsonArray * jsonArrayPtr;
    JsonObject * jsonObjectPtr;

};

#endif // JSONVALUE_H
