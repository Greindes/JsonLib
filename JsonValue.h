#ifndef JSONVALUE_H
#define JSONVALUE_H

#include<string>

class JsonObject;
class JsonArray;

class JsonValue
{
public:
    enum Type { Null, Bool, Int, String, Array, Object, Undefined };
    JsonValue();
    JsonValue(const JsonValue& other);
    JsonValue(bool b);
    JsonValue(int i);
    JsonValue(const std::string& s);
    JsonValue(const JsonArray& ja);
    JsonValue(const JsonObject& jo);
    ~JsonValue();

    bool isNull() const;
    bool isBool() const;
    bool isInt() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;
    bool isUndefined() const;

    bool toBool(bool defaultValue = false) const;
    double toInt(int defaultValue = 0) const;
    std::string toString(const std::string& defaultValue = "") const;
    JsonArray toArray(const JsonArray& defaultValue) const;
    JsonObject toObject(const JsonObject& defaultValue) const;

    Type type() const;
    void print(size_t tab = 0) const;

private:
    Type valueType = Undefined;
    bool boolValue = false;
    int intValue = 0;
    std::string stringValue = "";
    JsonArray * jsonArrayPtr = nullptr;
    JsonObject * jsonObjectPtr = nullptr;

};

#endif // JSONVALUE_H
