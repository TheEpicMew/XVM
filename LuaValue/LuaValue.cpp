#include "LuaValue.hpp"

LuaValue::LuaValue() : type(LUA_NIL) {}

LuaValue::LuaValue(double num) : type(LUA_NUMBER) {
    value.number = num;
}

LuaValue::LuaValue(bool b) : type(LUA_BOOL) {
    value.boolean = b;
}

LuaValue::LuaValue(const std::string& s) : type(LUA_STRING) {
    value.str = new std::string(s);
}

LuaValue::~LuaValue() {
    if (type == LUA_STRING) {
        delete value.str;
    }
}
