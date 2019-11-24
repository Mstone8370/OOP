#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_dict::json_dict() {

}

json_object* json_dict::parse(const char* str, int length) {
    json_dict* dict = new json_dict();
    while(_index < length) {
        _index++;
        char c = str[_index];
        json_object* key;
        if('0' <= c && c <= '9') {
            key = Integer::parse(str, length);
        } else if(c == '"' || c == '\'') {
            key = String::parse(str, length, c);
        } else if(c == ',' || c == ' ') {
            continue;
        }
        while((str[_index] == ':') || (str[_index] == ' ')) _index++;
        json_object* value = json_object::parse(str, length);

        // key가 있는지 검사
        json_object* val = (*dict)[key];
        if(val == nullptr) {
            // key가 v에 없는 경우
            (dict->v).push_back(std::make_pair(key, value));
        } else {
            // key가 v에 있는 경우
            int temp = _index;
            std::string key_str = key->to_string();
            for(int i = 0; i < dict->v.size(); ++i) {
                std::string current_key_str = dict->v[i].first->to_string();
                if(key_str.compare(current_key_str) == 0) {
                    dict->v[i].second = value;
                }
            }
            _index = temp;
        }

        if(str[_index] == '}') {
            _index++;
            break;
        }
    }
    // _index는 } 다음을 가리키고 있음
    return dict;
}

json_object* json_dict::operator[](json_object* key) const {
    int temp = _index;
    std::string key_str = key->to_string();
    for(int i = 0; i < v.size(); ++i) {
        std::string current_key_str = v[i].first->to_string();
        if(key_str.compare(current_key_str) == 0) {
            _index = temp;
            return v[i].second;
        }
    }
    _index = temp;
    return nullptr;
}

json_object* json_dict::operator[](const std::string& key) const {
    int temp = _index;
    std::string key_str = "'" + key + "'";
    for(int i = 0; i < v.size(); i++) {
        std::string current_key_str = v[i].first->to_string();
        if(key_str.compare(current_key_str) == 0) {
            _index = temp;
            return v[i].second;
        }
    }
    _index = temp;
    return nullptr;
}

json_object* json_dict::operator[](int key) const {
    int temp = _index;
    for(int i = 0; i < v.size(); i++) {
        std::string current_key_str = v[i].first->to_string();
        if((std::to_string(key)).compare(current_key_str) == 0) {
            _index = temp;
            return v[i].second;
        }
    }
    _index = temp;
    return nullptr;
}

json_object::_type json_dict::type() {
    return DICT;
}

std::string json_dict::to_string() {
    _index = 0;
    std::string str = "{";
    if(v.size() > 0) {
        for(auto iter = v.begin(); iter != v.end(); iter++) {
            str.append(iter->first->to_string());
            str.append(": ");
            str.append(iter->second->to_string());
            str.append(", ");
        }
        str.replace(str.length()-2, 2, "}");
    } else {
        str.append("}");
    }
    return str;
}