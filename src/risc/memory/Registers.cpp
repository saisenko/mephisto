#include "risc/memory/Registers.hpp"

void Registers::write_to_reg(const uint8_t& reg_addr, const uint32_t& data) {
    try {
        if (reg_addr <= 0 || reg_addr > 31) {
            throw reg_addr;
        } else {
            this->regs[reg_addr] = data;
        }
    } catch(int err) {
        switch (err) {
            case 0:
                std::cerr << "Operation denied. Cannot write to register x0/zero, which is always 0" << std::endl;
                break;        
            default:
                std::cerr << "Invalid register address provided. Expected [0-31], got {" << err << "}" << std::endl;
                break;
        }
    }
}

uint32_t Registers::fetch_from_reg(const uint8_t& reg_addr) {
    try {
        if (reg_addr < 0 || reg_addr > 31) {
            throw reg_addr;
        } else {
            return this->regs[reg_addr];
        }
    } catch(int err) {
        std::cerr << "Invalid register address provided. Expected [0-31], got {" << err << "}" << std::endl;
        return 1;
    }
}