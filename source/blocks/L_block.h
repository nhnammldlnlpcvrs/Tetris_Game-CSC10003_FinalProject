#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>

class LBlock : public Block
{
public:
    LBlock();
    static std::unique_ptr<LBlock> Create();
};
