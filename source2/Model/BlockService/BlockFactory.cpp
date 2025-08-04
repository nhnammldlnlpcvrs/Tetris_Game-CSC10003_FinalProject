#include "BlockFactory.h"

BlockFactory::BlockFactory() {
    _prototypes[0] = std::make_unique<IBlock>();
    _prototypes[1] = std::make_unique<JBlock>();
    _prototypes[2] = std::make_unique<LBlock>();
    _prototypes[3] = std::make_unique<OBlock>();
    _prototypes[4] = std::make_unique<SBlock>();
    _prototypes[5] = std::make_unique<TBlock>();
    _prototypes[6] = std::make_unique<ZBlock>();
}

std::unique_ptr<Block> BlockFactory::CreateBlock(int id) const {
    if (id < 0 || id >= static_cast<int>(_prototypes.size())) {
        throw std::out_of_range("Invalid Block ID: " + std::to_string(id));
    }

    auto clone = _prototypes[id]->Clone();
    if (!clone) {
        throw std::runtime_error("Failed to clone Block with ID: " + std::to_string(id));
    }

    return clone;
}


std::unique_ptr<Block> BlockFactory::CreateRandomBlock() const {
    return CreateBlock(GenerateRandomId());
}

int BlockFactory::GenerateRandomId() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 6);
    return dist(gen);
}
