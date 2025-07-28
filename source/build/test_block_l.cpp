#include "../libs/catch_amalgamated.hpp"
#include "../blocks/L_block.h"
#include <iostream>

TEST_CASE("Print LBlock positions after initialization", "[LBlock]") {
    LBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "LBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
