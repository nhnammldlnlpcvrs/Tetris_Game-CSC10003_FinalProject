#pragma once
#include <memory>
#include <array>
#include <random>

#include "Model/Block/IBlock.h"
#include "Model/Block/IBlock.h"
#include "Model/Block/IBlock.h"
#include "Model/Block/IBlock.h"
#include "Model/Block/JBlock.h"
#include "Model/Block/LBlock.h"
#include "Model/Block/OBlock.h"
#include "Model/Block/SBlock.h"
#include "Model/Block/TBlock.h"
#include "Model/Block/ZBlock.h"

class BlockFactory {
public:
    BlockFactory();

    // Tạo block theo id (0–6)
    std::unique_ptr<Block> CreateBlock(int id) const;

    // Tạo block ngẫu nhiên
    std::unique_ptr<Block> CreateRandomBlock() const;

private:
    std::array<std::unique_ptr<Block>, 7> _prototypes;

    int GenerateRandomId() const;
};
