#include "CLVM.hpp"
#include <sstream>
#include <iostream>

CLVM::CLVM() {
    initLua();
}

CLVM::~CLVM() {
    closeLua();
}

void CLVM::initLua() {
    L = luaL_newstate();  //lua state baby
    luaL_openlibs(L);
}

void CLVM::closeLua() {
    if (L) {
        lua_close(L);    
        L = nullptr;
    }
}

void CLVM::run(const std::string& bytecode) {
    std::istringstream stream(bytecode);
    std::string instruction;

    while (std::getline(stream, instruction)) {
        execute(instruction);
    }
}

void CLVM::execute(const std::string& bytecode) {
    std::istringstream iss(bytecode);
    std::string op;
    iss >> op;

    if (op == "PUSH") {
        std::string value;
        iss >> value;

        if (value == "true") {
            stack.push(LuaValue(true));   
        } else if (value == "false") {
            stack.push(LuaValue(false));  
        } else {
            stack.push(LuaValue(std::stod(value))); 
        }
    } else if (op == "PRINT") {
        LuaValue val = stack.pop();
        if (val.type == LUA_NUMBER) {
            std::cout << val.value.number << std::endl; 
        } else if (val.type == LUA_BOOL) {
            std::cout << (val.value.boolean ? "true" : "false") << std::endl;
        }
    }
}

void CLVM::loadLuaScript(const std::string& script) {
    if (luaL_loadstring(L, script.c_str()) || lua_pcall(L, 0, 0, 0)) {
        lua_pop(L, 1);
    }
}

void CLVM::runLuaFunction(const std::string& functionName) {
    lua_getglobal(L, functionName.c_str()); 
    if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
        lua_pop(L, 1);
    }
}
