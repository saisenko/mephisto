#ifndef SRLI_H
#define SRLI_H

#include "../ITypeInstruction.h"

class Srli : public ITypeInstruction {
public:
    Srli(uint8_t rd, uint8_t rs1, uint8_t imm) : ITypeInstruction(rd, rs1, imm) {}

    QString get_funct3() const override {return "101";}
    QString get_opcode() const override {return "0010011";}

    void execute(Registers& regs) override {
        uint32_t data1 = regs.fetch_from_reg(rs1);
        uint32_t res =  data1 >> imm;

        regs.write_to_reg(rd, res);
    }
};

#endif // SRLI_H
