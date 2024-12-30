#ifndef ITYPEINSTRUCTION_H
#define ITYPEINSTRUCTION_H

#include "Instruction.h"

class ITypeInstruction : public Instruction {
protected:
    uint8_t rd, rs1, imm;
public:
    ITypeInstruction(uint8_t rd, uint8_t rs1, uint8_t imm) : rd(rd), rs1(rs1), imm(imm){}

    virtual QString get_funct3() const = 0;  // Pure virtual
    virtual QString get_opcode() const = 0; // Pure virtual

    QString encode_to_binary() override {
        QString binary_imm = QString::fromStdString(std::bitset<12>(imm).to_string());
        QString binary_rd = QString::fromStdString(std::bitset<5>(rd).to_string());
        QString binary_rs1 = QString::fromStdString(std::bitset<5>(rs1).to_string());

        QString binary = binary_imm + binary_rs1 + get_funct3() + binary_rd + get_opcode();
        return binary;
    }
};

#endif //ITYPEINSTRUCTION_H
