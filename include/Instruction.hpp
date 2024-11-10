#ifndef instruction_hpp
#define instruction_hpp

#include <bitset>

class Instruction {
public:
    Instruction(const std::bitset<7>& opcode);

    std::bitset<7> get_opcode() const;
    void set_opcode(const std::bitset<7>& opcode);
private:
    std::bitset<7> opcode;
};

#endif // instruction_hpp
