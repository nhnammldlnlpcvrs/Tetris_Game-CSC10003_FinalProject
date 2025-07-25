#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>


class IBlock : public Block
{
public:
    IBlock();
    static std::unique_ptr<IBlock> Create();
};