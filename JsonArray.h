#ifndef JSONARRAY_H
#define JSONARRAY_H
#include"JsonLib_global.h"
#include<vector>
#include"JsonValue.h"

class JSONLIB_EXPORT JsonArray
{
public:
    JsonArray();
    JsonArray(const JsonArray& other);
    JsonArray& operator=(const JsonArray& other);
    static JsonArray getFromJsonString(const std::string& json);

    size_t size();
    bool empty();
    void pushBack(const JsonValue& value);
    void popBack();
    void clear();

    const JsonValue& operator[](size_t i) const;
    JsonValue& operator[](size_t i);

    std::string getJsonString(size_t space) const;

private:
    std::vector<JsonValue> values;
};

#endif // JSONARRAY_H
