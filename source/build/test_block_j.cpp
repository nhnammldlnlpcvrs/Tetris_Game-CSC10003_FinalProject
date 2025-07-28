#include "../libs/catch_amalgamated.hpp"
#include "../blocks/J_block.h"
#include <iostream>

TEST_CASE("Print JBlock positions after initialization", "[JBlock]") {
    JBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "JBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
