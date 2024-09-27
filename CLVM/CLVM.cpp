#include "CLVM.hpp"
#include <sstream>
#include <iostream>

CLVM::CLVM() {}

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
