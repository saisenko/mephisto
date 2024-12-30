#include "../../../include/risc/memory/Memory.h"

#include <QString>

uint8_t Memory::mem_fetch(unsigned address) {
    uint8_t data;
    if (address < 0 || address >= 128) {
        throw std::invalid_argument("Unsupported address" + std::to_string(address));
    } else {
        data = this->mem[address];
    }
    return data;
}

void Memory::mem_write(unsigned address, uint8_t data) {
    if (address < 0 || address >= 128) {
        throw std::invalid_argument("Unsupported address" + std::to_string(address));
    } else {
        this->mem[address] = data;
    }
}
