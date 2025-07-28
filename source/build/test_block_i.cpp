#include "../libs/catch_amalgamated.hpp"
#include "../blocks/I_block.h"
#include <iostream>

TEST_CASE("Print IBlock positions after initialization", "[IBlock]") {
    IBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "IBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
