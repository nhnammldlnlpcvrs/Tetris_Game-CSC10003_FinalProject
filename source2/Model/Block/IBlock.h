#pragma once
#include "../source2/Model/Block/Block.h"

class IBlock : public Block {
public:
    IBlock();

    std::unique_ptr<Block> Clone() const override;
};
