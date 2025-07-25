#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>


class OBlock : public Block
{
public:
    OBlock();
    static std::unique_ptr<OBlock> Create();
};