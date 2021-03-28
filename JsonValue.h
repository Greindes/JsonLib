#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <string>

class JsonValue
{
public:
    enum Type { Null, Bool, Double, String, Array, Object, Undefined };
    JsonValue();
    JsonValue(bool b);
    JsonValue(double d);
    JsonValue(const std::string& s);
    //JsonValue(JsonArray);
    //JsonValue(JsonObject);

    bool isNull() const;
    bool isBool() const;
    bool isDouble() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;
    bool isUndefined() const;

    bool toBool(bool defaultValue = false) const;
    bool toDouble(double defaultValue = 0.0) const;
    bool toString(const std::string& defaultValue = "") const;
    //bool toArray(const JsonArray& defaultValue = JsonArray()) const
    //bool toObject(const JsonObject& defaultValue = JsonObject()) const

    Type type();

private:
    Type valueType = Null;
};

#endif // JSONVALUE_H
