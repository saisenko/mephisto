#ifndef SLTI_H
#define SLTI_H

#include "../ITypeInstruction.h"

class Slti : public ITypeInstruction {
public:
    Slti(uint8_t rd, uint8_t rs1, uint8_t imm) : ITypeInstruction(rd, rs1, imm) {}

    void execute(Registers& regs) override {
        uint32_t data1 = regs.fetch_from_reg(rs1);
        uint32_t res = (data1 < imm) ? 1 : 0;

        regs.write_to_reg(rd, res);
    }
};

#endif // SLTI_H
