#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include<string>
#include<list>
#include"JsonValue.h"

class JsonObject
{
public:
    JsonObject();
    class iterator
    {
        friend class JsonObject;
    public:
        iterator();

        std::string key() const;
        JsonValue value() const;
        iterator& operator=(iterator& other);
        iterator operator++();
        iterator operator--();
        JsonValue& operator*() const;
    private:
        std::list<std::pair<std::string, JsonValue>>::iterator iter;

        void setIter(std::list<std::pair<std::string, JsonValue>>::iterator i);
    };

    bool isEmpty();
    size_t size();

    JsonValue get(std::string key) const;

    iterator find(std::string key) const;
    iterator begin() const;
    iterator end() const;

    iterator insert(const std::string& key, const JsonValue& value);
    void remove(const std::string& key);

private:
    std::list<std::pair<std::string, JsonValue>> values;
    size_t valsSize;
};

#endif // JSONOBJECT_H
