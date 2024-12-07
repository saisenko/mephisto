#ifndef instruction_hpp
#define instruction_hpp

#include <cstdint>
#include <string>

class Instruction {
protected:
    uint32_t opcode, binary;
public:
    explicit Instruction(uint32_t binary) : binary(binary)
    {
        this->opcode = (binary >> 10) & 0b1111111;
    }

    virtual void decode() = 0;
    virtual std::string to_mnemonic() = 0;

    virtual ~Instruction() = default; 
};

#endif // instruction_hpp
