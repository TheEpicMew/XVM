#ifndef CLVM_HPP
#define CLVM_HPP

#include "LuaStack.hpp"
#include <string>

class CLVM {
public:
    CLVM();
    void run(const std::string& bytecode);
    
private:
    LuaStack stack;
    void execute(const std::string& bytecode);
};

#endif
