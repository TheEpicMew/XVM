#include "LuaStack.hpp"

void LuaStack::push(const LuaValue& val) {
    stack.push(val);
}

LuaValue LuaStack::pop() {
    if (stack.empty()) return LuaValue();
    LuaValue val = stack.top();
    stack.pop();
    return val;
}
