#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instructions/Instruction.h"

#include "instructions/r_type/Add.h"
#include "instructions/r_type/Sub.h"
#include "instructions/r_type/Slt.h"
#include "instructions/r_type/And.h"
#include "instructions/r_type/Or.h"
#include "instructions/r_type/Xor.h"
#include "instructions/r_type/Sll.h"
#include "instructions/r_type/Srl.h"

#include "instructions/i_type/Addi.h"
#include "instructions/i_type/Slti.h"
#include "instructions/i_type/Andi.h"
#include "instructions/i_type/Ori.h"
#include "instructions/i_type/Xori.h"
#include "instructions/i_type/Slli.h"
#include "instructions/i_type/Srli.h"


class InstructionFactory {
public:
    static Instruction* createInstruction(const QString& name, const QStringList& args) {
        if (name == "add") {
            return new Add(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "sub") {
            return new Sub(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "slt") {
            return new Slt(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "and") {
            return new And(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "or") {
            return new Or(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "xor") {
            return new Xor(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "sll") {
            return new Sll(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "srl") {
            return new Srl(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "addi") {
            return new Addi(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "slti") {
            return new Slti(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "andi") {
            return new Andi(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "ori") {
            return new Ori(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "xori") {
            return new Xori(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "slli") {
            return new Slli(args[0].toInt(), args[1].toInt(), args[2].toInt());
        } else if (name == "srli") {
            return new Srli(args[0].toInt(), args[1].toInt(), args[2].toInt());
        }
        // Add more instruction types here
        throw std::invalid_argument("Unsupported instruction: " + name.toStdString());
    }
};


#endif // INSTRUCTIONFACTORY_H
