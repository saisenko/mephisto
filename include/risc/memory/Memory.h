#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

class Memory {
private:
    uint8_t mem[128] = { };
public:
    uint8_t mem_fetch(unsigned address);
    void mem_write(unsigned address, uint8_t data);
};

#endif // MEMORY_H
