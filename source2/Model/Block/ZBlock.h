#pragma once
#include "../source2/Model/Block/Block.h"

class ZBlock : public Block {
public:
    ZBlock();
    std::unique_ptr<Block> Clone() const override;
};
