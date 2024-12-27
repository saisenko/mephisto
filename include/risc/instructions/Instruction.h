#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QString>
#include <QMap>
#include "../memory/Registers.h"

class Instruction {
public:
    virtual ~Instruction() = default;

    virtual void execute(Registers& regs) = 0;
};

#endif //INSTRUCTION_H
