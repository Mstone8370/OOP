#include "Integer.h"

Integer::Integer(int value) {
    this->_val = value;
}

int Integer::val() {
    return _val;
}

void Integer::set_val(const int& value) {
    this->_val = value;
}

json_object* Integer::parse(const char* str, int length) {
    char value[10];
    int i = 0;
    while(_index < length) {
        char c = str[_index];
        if('0' <= c && c <= '9') {
            value[i] = c;
        } else {
            i++;
            break;
        }
        _index++;
        i++;
    }
    // _index는 숫자가 아닌 곳을 가리키고 있음
    value[i] = '\0';
    json_object* int_value = new Integer(atoi(value));
    return int_value;
}

json_object::_type Integer::type() {
    return INT;
}

std::string Integer::to_string() {
    _index = 0;
    return std::to_string(_val);
}