#pragma once
#include <memory>
#include <array>
#include <random>

#include "../source2/Model/Block/IBlock.h"
#include "../source2/Model/Block/IBlock.h"
#include "../source2/Model/Block/IBlock.h"
#include "../source2/Model/Block/IBlock.h"
#include "../source2/Model/Block/JBlock.h"
#include "../source2/Model/Block/LBlock.h"
#include "../source2/Model/Block/OBlock.h"
#include "../source2/Model/Block/SBlock.h"
#include "../source2/Model/Block/TBlock.h"
#include "../source2/Model/Block/ZBlock.h"

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
