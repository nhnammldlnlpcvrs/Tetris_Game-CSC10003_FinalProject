#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>


class ZBlock : public Block
{
public:
    ZBlock();
    static std::unique_ptr<ZBlock> Create();
};