#pragma once
#include "../source2/Model/Block/Block.h"

class TBlock : public Block {
public:
    TBlock();
    std::unique_ptr<Block> Clone() const override;
};
