#ifndef registers_hpp
#define registers_hpp

#include <cstdint>
#include <string>

class Registers {
protected:
    uint32_t regs[32] = { };
public:
    void write_to_reg(const uint8_t& reg_addr, const uint32_t& data);
    [[nodiscard]] uint32_t fetch_from_reg(const uint8_t& reg_addr);
    [[nodiscard]] std::string get_all_regs_data();
};

#endif // registers_hpp