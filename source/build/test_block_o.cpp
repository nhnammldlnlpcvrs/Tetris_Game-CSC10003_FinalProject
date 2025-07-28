#include "../libs/catch_amalgamated.hpp"
#include "../blocks/O_block.h"
#include <iostream>

TEST_CASE("Print OBlock positions after initialization", "[OBlock]") {
    OBlock block;
    auto positions = block.GetCellPositions();

    std::cout << "OBlock initial positions:\n";
    for (const auto& pos : positions) {
        std::cout << "(" << pos.row << ", " << pos.column << ")\n";
    }

    REQUIRE(positions.size() == 4);
}
