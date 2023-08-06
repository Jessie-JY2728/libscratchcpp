// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <vector>
#include <cstddef>
#include <scratchcpp/global.h>

namespace libscratchcpp
{

class VirtualMachine;
class Target;
class IEngine;
class Script;
class Value;
class List;

struct VirtualMachinePrivate
{
        VirtualMachinePrivate(VirtualMachine *vm, Target *target, IEngine *engine, Script *script);
        VirtualMachinePrivate(const VirtualMachinePrivate &) = delete;
        ~VirtualMachinePrivate();

        unsigned int *run(unsigned int *pos);

        static const unsigned int instruction_arg_count[];

        typedef struct
        {
                bool isRepeatLoop;
                unsigned int *start;
                size_t index, max;
        } Loop;

        unsigned int *bytecode = nullptr;
        std::vector<unsigned int> bytecodeVector;

        VirtualMachine *vm = nullptr;
        Target *target = nullptr;
        IEngine *engine = nullptr;
        Script *script = nullptr;
        unsigned int *pos = nullptr;
        unsigned int *checkpoint = nullptr;
        bool atEnd = false;
        std::vector<Loop> loops;
        std::vector<unsigned int *> callTree;
        std::vector<std::vector<Value>> procedureArgTree;
        std::vector<Value> *procedureArgs = nullptr;
        std::vector<Value> *nextProcedureArgs = nullptr;
        bool atomic = true;
        bool warp = false;
        bool stop = false;
        bool savePos = true;
        bool goBack = false;
        bool updatePos = false;

        unsigned int **procedures = nullptr;
        BlockFunc *functions;
        const Value *constValues = nullptr;
        Value **variables = nullptr;
        List **lists = nullptr;

        Value **regs = nullptr;
        size_t regCount = 0;
};

} // namespace libscratchcpp