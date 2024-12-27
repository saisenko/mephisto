#ifndef RTYPEINSTRUCTION_H
#define RTYPEINSTRUCTION_H

#include "Instruction.h"

class RTypeInstruction : public Instruction {
protected:
    uint8_t rd, rs1, rs2;
public:
    RTypeInstruction(uint8_t rd, uint8_t rs1, uint8_t rs2) : rd(rd), rs1(rs1), rs2(rs2){}
};

#endif //RTYPEINSTRUCTION_H
