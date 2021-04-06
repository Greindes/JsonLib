#include"JsonArray.h"
#include<iostream>


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

void JsonArray::print(size_t tab) const
{
    size_t size = values.size();
    std::cout << '[';
    for (size_t i = 0; i < size; ++i) {
        values[i].print(tab);
        if (i < size - 1)
            std::cout << std::string(tab, ' ') << ", ";
    }
    std::cout << std::string(tab, ' ') << "]\n";
}

JsonValue &JsonArray::operator[](size_t i)
{
    return values[i];
}
