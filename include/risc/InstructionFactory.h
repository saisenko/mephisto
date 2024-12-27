#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instructions/Instruction.h"

#include "instructions/r_type/Add.h"
#include "instructions/r_type/Sub.h"
#include "instructions/r_type/Slt.h"

#include "instructions/i_type/Addi.h"
#include "instructions/i_type/Slti.h"

class InstructionFactory {
public:
    static Instruction* createInstruction(const QString& name, const QStringList& args) {
        if (name == "add") {
            return new Add(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "sub") {
            return new Sub(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "slt") {
            return new Slt(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "addi") {
            return new Addi(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "slti") {
            return new Slti(args[0].toInt(), args[1].toInt(), args[2].toInt());
        }
        // Add more instruction types here
        throw std::invalid_argument("Unsupported instruction: " + name.toStdString());
    }
};


#endif // INSTRUCTIONFACTORY_H
