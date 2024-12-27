#ifndef ADD_H
#define ADD_H

#include "../RTypeInstruction.h"

class Add : public RTypeInstruction {
public:
    Add(uint8_t rd, uint8_t rs1, uint8_t rs2) : RTypeInstruction(rd, rs1, rs2) {}

    void execute(Registers& regs) override {
        uint32_t data1 = regs.fetch_from_reg(rs1);
        uint32_t data2 = regs.fetch_from_reg(rs2);
        uint32_t res =  data1 + data2;

        regs.write_to_reg(rd, res);
    }
};

#endif // ADD_H
