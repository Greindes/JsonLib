#include "JsonArray.h"

JsonArray::JsonArray()
{

}

size_t JsonArray::size()
{
    return values.size();
}

void JsonArray::pushBack(const JsonValue &value)
{
    values.push_back(value);
}

void JsonArray::popBack()
{
    values.pop_back();
}

void JsonArray::clear()
{
    values.clear();
}

const JsonValue &JsonArray::operator[](size_t i) const
{
    return values[i];
}

JsonValue &JsonArray::operator[](size_t i)
{
    return values[i];
}
