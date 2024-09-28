#ifndef CLVM_HPP
#define CLVM_HPP

#include "LuaStack.hpp"
#include <string>
extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

class CLVM {
public:
    CLVM();
    ~CLVM();
    void run(const std::string& bytecode);
    void LoadScript(const std::string& script);
    void RunScript(const std::string& functionName);
    
private:
    LuaStack stack;
    lua_State* L;
    void execute(const std::string& bytecode);
    void initLua();  
    void closeLua(); 
};

#endif // CLVM_HPP
