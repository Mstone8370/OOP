#include "json_object.h"
#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const char* str, int length) {
    char c = str[_index];
    if(c == '{') {
        return json_dict::parse(str, length);
    } else if(c == '[') {
        return json_list::parse(str, length);
    } else if('0' <= c && c <= '9') {
        return Integer::parse(str, length);
    } else if(c == '"' || c == '\'') {
        return String::parse(str, length, c);
    }
    return nullptr;
}

json_object* json_object::parse(const std::string& str) {
    const char* c = str.c_str();
    parse(c, str.length());
}