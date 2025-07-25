#pragma once 
#include "../data/block.h"
#include "../core/position.h"
#include <memory>

class JBlock : public Block
{
public:
    JBlock();
    static std::unique_ptr<JBlock> Create();
};