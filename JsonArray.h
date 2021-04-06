#ifndef JSONARRAY_H
#define JSONARRAY_H

#include<vector>
#include"JsonValue.h"

class JsonArray
{
public:
    JsonArray();

    size_t size();
    bool empty();
    void pushBack(const JsonValue& value);
    void popBack();
    void clear();

    const JsonValue& operator[](size_t i) const;
    JsonValue& operator[](size_t i);

    void print(size_t tab) const;

private:
    std::vector<JsonValue> values;
};

#endif // JSONARRAY_H
