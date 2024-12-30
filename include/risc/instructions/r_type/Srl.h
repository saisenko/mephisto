#ifndef SRL_H
#define SRL_H

#include "../RTypeInstruction.h"

class Srl : public RTypeInstruction {
public:
    Srl(uint8_t rd, uint8_t rs1, uint8_t rs2) : RTypeInstruction(rd, rs1, rs2) {}

    QString get_funct3() const override {return "101";}
    QString get_funct7() const override {return "0000000";}
    QString get_opcode() const override {return "0110011";}

    void execute(Registers& regs) override {
        uint32_t data1 = regs.fetch_from_reg(rs1);
        uint32_t data2 = regs.fetch_from_reg(rs2);
        uint32_t res =  data1 >> data2;

        regs.write_to_reg(rd, res);
    }
};

#endif // SRL_H
