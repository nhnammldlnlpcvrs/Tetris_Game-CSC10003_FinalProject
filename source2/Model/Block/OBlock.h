#pragma once
#include "../source2/Model/Block/Block.h"

class OBlock : public Block {
public:
    OBlock();
    std::unique_ptr<Block> Clone() const override;
};
