#pragma once
#include "../source2/Model/Block/Block.h"

class LBlock : public Block {
public:
    LBlock();
    std::unique_ptr<Block> Clone() const override;
};
