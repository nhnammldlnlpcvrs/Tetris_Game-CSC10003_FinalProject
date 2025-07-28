#define CATCH_CONFIG_MAIN

#include "../libs/catch_amalgamated.hpp"
#include "../core/grid.h"

TEST_CASE("Print on console", "[Grid][Print]") {
    Grid grid;

    SECTION("Create grid and print") {
        grid.Initialize();
        grid.Print();
        for (int row = 0; row < 20; row++) {
            for (int col = 0; col < 10; col++) {
                REQUIRE(grid.grid[row][col] == 0);
            }
        }
    }
}