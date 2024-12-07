#include "risc/memory/Registers.hpp"

#include <iostream>
#include <sstream>

void Registers::write_to_reg(const uint8_t& reg_addr, const uint32_t& data) {
    try {
        if (reg_addr == 0) {
            throw std::invalid_argument("Cannot write to x0 (zero register).");
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

std::string Registers::get_all_regs_data() {
    std::stringstream ss;
    for (uint8_t i = 0; i < 32; i++) {
        ss << "x" << i << ": " << this->regs[i] << "\n";
    }
    return ss.str();
}