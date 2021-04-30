#ifndef JSONOBJECT_H
#define JSONOBJECT_H
#include"JsonLib_global.h"
#include<string>
#include<list>
#include"JsonValue.h"

class JSONLIB_EXPORT JsonObject
{
public:
    using list = std::list<std::pair<std::string, JsonValue>>;

    JsonObject();
    JsonObject(const JsonObject& other);
    JsonObject & operator=(const JsonObject& other);
    static JsonObject getFromJsonString(const std::string& json);

    bool isEmpty() const;
    size_t size() const;

    JsonValue& get(std::string key);
    const JsonValue& get(std::string key) const;

    void insert(const std::string& key, const JsonValue& value);
    void remove(const std::string& key);

    list::iterator find(std::string key);
    list::const_iterator find(std::string key) const;

    std::string getJsonString(size_t space = 0) const;
    const list& getValues() const;
    list& getValues();
private:
    list values;
    size_t valsSize = 0;
};

#endif // JSONOBJECT_H
