#include "../libs/catch_amalgamated.hpp"
#include "../blocks/Z_block.h"
#include <iostream>

TEST_CASE("Print ZBlock positions after initialization", "[ZBlock]") {
    ZBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "ZBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
