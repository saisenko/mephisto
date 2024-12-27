#include "../../../include/risc/memory/Registers.h"

#include <iostream>

#include <QList>

void Registers::write_to_reg(const uint8_t& reg_addr, const uint32_t& data) {
    try {
        if (reg_addr == 0) {
            this->regs[reg_addr] = 0;
        }
        if (reg_addr > 31) {
            throw std::out_of_range("Invalid register address.");
        }
        this->regs[reg_addr] = data;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

uint32_t Registers::fetch_from_reg(const uint8_t& reg_addr) {
    if (reg_addr > 31) {
        throw std::out_of_range("Invalid register address.");
    }
    return this->regs[reg_addr];
}

QList<int> Registers::get_all_regs_data() {
    QList<int> regs_data;
    for (size_t i = 0; i < 32; i++) {
        regs_data.append(this->fetch_from_reg(i));
    }
    return regs_data;
}
