#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list() {
    
}

json_object* json_list::parse(const char* str, int length) {
    json_list* list = new json_list();
    while(_index < length) {
        _index++;
        char c = str[_index];
        if(c == '{') {
            json_object* obj = json_dict::parse(str, length);
            (list->v).push_back(obj);
        } else if(c == '[') {
            json_object* obj = json_list::parse(str, length);
            (list->v).push_back(obj);
        } else if('0' <= c && c <= '9') {
            json_object* obj = Integer::parse(str, length);
            (list->v).push_back(obj);
        } else if(c == '"' || c == '\'') {
            json_object* obj = String::parse(str, length, c);
            (list->v).push_back(obj);
        }
        
        if(str[_index] == ']') {
            _index++;
            break;
        }
    }
    // _index는 ] 다음을 가리키고 있음
    return list;
}

json_object* json_list::operator[](int key) const {
    return v[key];
}

json_object::_type json_list::type() {
    return LIST;
}

std::string json_list::to_string() {
    _index = 0;
    std::string str = "[";
    if(v.size() > 0) {
        for(auto iter = v.begin(); iter != v.end(); iter++) {
            str.append((*iter)->to_string());
            str.append(", ");
        }
        str.replace(str.length()-2, 2, "]");
    } else {
        str.append("]");
    }
    return str;
}