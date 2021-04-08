#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include<string>
#include<list>
#include"JsonValue.h"

class JsonObject
{
public:
    JsonObject();
    static JsonObject getFromJsonString(const std::string& json);
    class iterator
    {
        friend class JsonObject;
    public:
        iterator();
        iterator(const iterator& other);
        std::string key() const;
        JsonValue value() const;
        iterator& operator=(iterator& other);
        iterator operator++();
        iterator operator--();
        JsonValue& operator*() const;
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    private:
        std::list<std::pair<std::string, JsonValue>>::iterator iter;
    };

    bool isEmpty();
    size_t size();

    JsonValue get(std::string key);

    iterator find(std::string key);
    iterator begin();
    iterator end();

    void insert(const std::string& key, const JsonValue& value);
    void remove(const std::string& key);

    std::string getJsonString(size_t space = 0) const;
    void print(size_t t = 0) const;
private:
    std::list<std::pair<std::string, JsonValue>> values;
    size_t valsSize;
};

#endif // JSONOBJECT_H
