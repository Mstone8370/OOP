#include "String.h"

String::String(const std::string &str) {
    this->_val = str;
}

std::string String::val() {
    return _val;
}

void String::set_val(const std::string& str) {
    this->_val = str;
}

json_object* String::parse(const char* str, int length, char base) {
    std::string value = "";
    while(_index < length) {
        _index++;
        char c = str[_index];
        if(c == base) {
            json_object* str_value = new String(value);
            _index++;
            return str_value;
            // _index는 base 다음을 가리키고 있음
        } else {
            value.append(&c, 1);
        }
    }
}

json_object::_type String::type() {
    return STRING;
}

std::string String::to_string() {
    _index = 0;
    return "'" + _val + "'";
}