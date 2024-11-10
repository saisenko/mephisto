#include "Instruction.hpp"

Instruction::Instruction(const std::bitset<7>& opcode) : opcode() {}

std::bitset<7> Instruction::get_opcode() const {
    return opcode;
}

void Instruction::set_opcode(const std::bitset<7>& opcode) {
    this->opcode = opcode;
}
