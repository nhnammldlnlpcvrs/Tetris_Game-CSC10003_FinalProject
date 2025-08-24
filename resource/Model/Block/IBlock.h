#pragma once
#include "Model/Block/Block.h"

class IBlock : public Block {
public:
    IBlock();

    // Trả về màu của từng cell, đảm bảo vector cùng size với số cell
    std::vector<Color> GetCellColor() const override;
    
    std::unique_ptr<Block> Clone() const override;
};
