// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <vector>
#include <scratchcpp/value.h>

#include "engine/internal/global.h"

namespace libscratchcpp
{

class Target;
class IEngine;
class List;

struct ScriptPrivate
{
        ScriptPrivate(Target *target, IEngine *engine);
        ScriptPrivate(const ScriptPrivate &) = delete;

        unsigned int *bytecode = nullptr;
        std::vector<unsigned int> bytecodeVector;

        Target *target = nullptr;
        IEngine *engine = nullptr;

        unsigned int **procedures = nullptr;
        std::vector<unsigned int *> proceduresVector;

        BlockFunc *functions = nullptr;
        std::vector<BlockFunc> functionsVector;

        const Value *constValues = nullptr;
        std::vector<Value> constValuesVector;

        Value **variables = nullptr;
        std::vector<Value *> variablesVector;

        List **lists = nullptr;
        std::vector<List *> listsVector;
};

} // namespace libscratchcpp
