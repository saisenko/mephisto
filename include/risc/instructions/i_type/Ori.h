#ifndef ORI_H
#define ORI_H

#include "../ITypeInstruction.h"

class Ori : public ITypeInstruction {
public:
    Ori(uint8_t rd, uint8_t rs1, uint8_t imm) : ITypeInstruction(rd, rs1, imm) {}

    QString get_funct3() const override {return "110";}
    QString get_opcode() const override {return "0010011";}

    void execute(Registers& regs) override {
        uint32_t data1 = regs.fetch_from_reg(rs1);
        uint32_t res =  data1 | imm;

        regs.write_to_reg(rd, res);
    }
};

#endif // ORI_H