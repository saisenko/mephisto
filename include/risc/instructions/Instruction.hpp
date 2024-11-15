#ifndef instruction_hpp
#define instruction_hpp

#include <stdint.h>
#include <string>

class Instruction {
protected:
    uint32_t opcode;
    uint32_t binary;
public:
    Instruction(uint32_t binary) : binary(binary) {}

    virtual void decode() = 0;
    virtual std::string to_mnemonic() = 0;

    virtual ~Instruction() = default; 
};

#endif // instruction_hpp
