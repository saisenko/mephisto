#ifndef registers_hpp
#define registers_hpp

#include <iostream>
#include <stdint.h>

class Registers {
protected:
    uint32_t regs[32] = { };
public:
    void write_to_reg(const uint8_t& reg_addr, const uint32_t& data);
    uint32_t fetch_from_reg(const uint8_t& reg_addr);
};

#endif // registers_hpp