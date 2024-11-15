#ifndef translator_hpp
#define translator_hpp

#include <string>

class Translator {
public:
    Translator();
    void load_asm_instruction();
    void execute_asm_instruction();
private:
    Memory memory;
    Registers regs;
    Instruction current_instruction;

    void decode_asm_instruction(const std::string& instruction);
    void execute();
}

#endif // translator_hpp
