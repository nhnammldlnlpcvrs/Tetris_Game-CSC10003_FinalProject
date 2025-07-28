#include "../libs/catch_amalgamated.hpp"
#include "../blocks/S_block.h"
#include <iostream>

TEST_CASE("Print SBlock positions after initialization", "[SBlock]") {
    SBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "SBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
