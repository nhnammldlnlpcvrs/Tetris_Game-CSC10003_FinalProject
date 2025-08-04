#pragma once
#include <memory>
#include "../../Model/Block/Block.h"

class RandomBlockGenerator {
public:
    static std::unique_ptr<Block> Generate(int gridColumns);
};
