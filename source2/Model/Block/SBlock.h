#pragma once
#include "../source2/Model/Block/Block.h"

class SBlock : public Block {
public:
    SBlock();
    std::unique_ptr<Block> Clone() const override;
};
