#ifndef RTYPEINSTRUCTION_H
#define RTYPEINSTRUCTION_H

#include "Instruction.h"

class RTypeInstruction : public Instruction {
protected:
    uint8_t rd, rs1, rs2;
public:
    RTypeInstruction(uint8_t rd, uint8_t rs1, uint8_t rs2) : rd(rd), rs1(rs1), rs2(rs2){}

    virtual QString get_funct3() const = 0;  // Pure virtual
    virtual QString get_funct7() const = 0;  // Pure virtual
    virtual QString get_opcode() const = 0; // Pure virtual

    QString encode_to_binary() override {
        QString binary_rd = QString::fromStdString(std::bitset<5>(rd).to_string());
        QString binary_rs1 = QString::fromStdString(std::bitset<5>(rs1).to_string());
        QString binary_rs2 = QString::fromStdString(std::bitset<5>(rs2).to_string());

        QString binary = get_funct7() + binary_rs2 + binary_rs1 + get_funct3() + binary_rd + get_opcode();
        return binary;
    }
};

#endif //RTYPEINSTRUCTION_H
