#pragma once
#include "../source2/Model/Block/Block.h"

class JBlock : public Block {
public:
    JBlock();

    std::unique_ptr<Block> Clone() const override;
};
