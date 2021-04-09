#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include<string>
#include<list>
#include"JsonValue.h"

class JsonObject
{
public:
    JsonObject();
    JsonObject(const JsonObject& other);
    JsonObject & operator=(const JsonObject& other);
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

    bool isEmpty() const;
    size_t size() const;

    JsonValue& get(std::string key);

    iterator find(std::string key);
    iterator begin();
    iterator end();

    void insert(const std::string& key, const JsonValue& value);
    void remove(const std::string& key);

    std::string getJsonString(size_t space = 0) const;
private:
    std::list<std::pair<std::string, JsonValue>> values;
    size_t valsSize;
};

#endif // JSONOBJECT_H
