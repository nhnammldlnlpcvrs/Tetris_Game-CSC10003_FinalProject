#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>


class SBlock : public Block
{
public:
    SBlock();
    static std::unique_ptr<SBlock> Create();
};