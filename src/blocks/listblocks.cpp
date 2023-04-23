// SPDX-License-Identifier: Apache-2.0

#include "listblocks.h"
#include <iostream>

using namespace libscratchcpp;

ListBlocks::ListBlocks()
{
}

std::string ListBlocks::name() const
{
    return "Lists";
}

bool ListBlocks::categoryVisible() const
{
    return false;
}