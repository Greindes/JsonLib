#ifndef JSONVALUE_H
#define JSONVALUE_H
#include"JsonLib_global.h"
#include<string>
#include<memory>
#include<variant>

class JsonObject;
class JsonArray;

class JSONLIB_EXPORT JsonValue
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
    JsonValue & operator=(const JsonValue& other);

    static JsonValue getNullValue();

    bool isNull() const;
    bool isBool() const;
    bool isInt() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;
    bool isUndefined() const;

    bool toBool(bool defaultValue = false) const;
    int toInt(int defaultValue = 0) const;
    std::string toString(const std::string& defaultValue = "") const;
    JsonArray toArray(const JsonArray& defaultValue) const;
    JsonObject toObject(const JsonObject& defaultValue) const;

    Type type() const;
    std::string getJsonString(size_t space = 0) const;

private:
    std::variant<bool, int, std::string, std::unique_ptr<JsonArray>,
                    std::unique_ptr<JsonObject>> value = 0;

    Type valueType = Undefined;
};

#endif // JSONVALUE_H
