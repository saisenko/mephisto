#include <iostream>
#include <string>


#include "risc/memory/Registers.hpp"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid input. Expected 2 args." << std::endl;
    }

    std::string user_input = argv[1];
    std::cout << user_input << std::endl;

    Registers regs;
    // test 1
    regs.write_to_reg(2, 0x5A);
    uint32_t fetched_data_1 = regs.fetch_from_reg(2);
    std::cout << "Fetched " << fetched_data_1 << " from register 2" << std::endl;

    // test 2
    regs.write_to_reg(0, 0xAA);
    uint32_t fetched_data_2 = regs.fetch_from_reg(0);
    std::cout << "Fetched " << fetched_data_2 << " from register 0" << std::endl;

    return 0;
}
