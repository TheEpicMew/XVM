#include "CLVM.hpp"

int main() {
    CLVM vm;
    std::string bytecode = "PUSH 10\nPUSH true\nPRINT\nPRINT";
    vm.run(bytecode);
    return 0;
}
