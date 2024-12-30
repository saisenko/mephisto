#ifndef ADDI_H
#define ADDI_H

#include "../ITypeInstruction.h"

class Addi : public ITypeInstruction {
protected:
    QString funct3 = "000";
    QString opcode = "0010011";
public:
    Addi(uint8_t rd, uint8_t rs1, uint8_t imm) : ITypeInstruction(rd, rs1, imm) {}

    QString get_funct3() const override {return "000";}
    QString get_opcode() const override {return "0010011";}

    void execute(Registers& regs) override {
        uint32_t data1 = regs.fetch_from_reg(rs1);
        uint32_t res =  data1 + static_cast<int16_t>(imm);

        regs.write_to_reg(rd, res);
    }
};

#endif // ADDI_H
