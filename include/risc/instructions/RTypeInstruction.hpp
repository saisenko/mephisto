#ifndef rtypeinstruction_hpp
#define rtypeinstruction_hpp

#include "Instruction.hpp"

class RTypeInstruction : public Instruction {
protected:
    uint32_t rs1, rs2, rd, funct3, funct7;
public:
    RTypeInstruction(uint32_t binary) : Instruction(binary) { decode(); }

    void decode() override;
    std::string to_mnemonic() override;
};

#endif // rtypeinstruction_hpp