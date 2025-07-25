#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>


class TBlock : public Block
{
public:
    TBlock();
    static std::unique_ptr<TBlock> Create();
};