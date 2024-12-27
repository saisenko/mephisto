#ifndef ITYPEINSTRUCTION_H
#define ITYPEINSTRUCTION_H

#include "Instruction.h"

class ITypeInstruction : public Instruction {
protected:
    uint8_t rd, rs1, imm;
public:
    ITypeInstruction(uint8_t rd, uint8_t rs1, uint8_t imm) : rd(rd), rs1(rs1), imm(imm){}
};

#endif //ITYPEINSTRUCTION_H
