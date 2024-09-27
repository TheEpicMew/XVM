#ifndef LUAVALUE_HPP
#define LUAVALUE_HPP

#include <string>

enum LuaType {
    LUA_NUMBER,
    LUA_STRING,
    LUA_BOOL,
    LUA_NIL
};

struct LuaValue {
    LuaType type;
    union {
        double number;
        bool boolean;
        std::string* str;
    } value;

    LuaValue();
    LuaValue(double num);
    LuaValue(bool b);
    LuaValue(const std::string& s);
    ~LuaValue();
};

#endif

