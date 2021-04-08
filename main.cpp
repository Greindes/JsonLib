#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <fstream>
#include <streambuf>
#include"JsonObject.h"


int main()
{
    std::ifstream t("D:/CPP/build-JsonLib-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/txt.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    auto obj = JsonObject::getFromJsonString(str);
    std::string json = obj.getJsonString();
    auto obj2 = JsonObject::getFromJsonString(json);
    obj2.print();
    return 0;
}
