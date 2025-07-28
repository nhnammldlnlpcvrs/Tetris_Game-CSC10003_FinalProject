#include "../libs/catch_amalgamated.hpp"
#include "../blocks/T_block.h"
#include <iostream>

TEST_CASE("Print TBlock positions after initialization", "[TBlock]") {
    TBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "TBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
