#include "../libs/catch_amalgamated.hpp"

#include "../blocks/I_block.h"
#include "../blocks/J_block.h"
#include "../blocks/L_block.h"
#include "../blocks/O_block.h"
#include "../blocks/S_block.h"
#include "../blocks/T_block.h"
#include "../blocks/Z_block.h"

#include <iostream>
#include <vector>
#include <string>

// Hàm in danh sách ô
void printPositions(const std::vector<Position>& positions, const std::string& label) {
    std::cout << label << ":\n";
    for (const auto& p : positions) {
        std::cout << "(" << p.row << ", " << p.column << ")\n";
    }
    std::cout << '\n';
}

// Hàm test xoay block bất kỳ
template <typename T>
void testBlockRotation(const std::string& blockName) {
    T block;

    auto original = block.GetCellPositions();

    block.Rotate(); // xoay phải
    auto rotated = block.GetCellPositions();

    block.UndoRotation(); // xoay ngược lại
    auto reverted = block.GetCellPositions();

    printPositions(original, blockName + " - Original");
    printPositions(rotated, blockName + " - After Rotate()");
    printPositions(reverted, blockName + " - After UndoRotation()");

    REQUIRE(original.size() == 4);
    REQUIRE(rotated.size() == 4);
    REQUIRE(reverted.size() == 4);
    REQUIRE(reverted == original); 
}

TEST_CASE("Rotate IBlock", "[Rotate]") {
    testBlockRotation<IBlock>("IBlock");
}

TEST_CASE("Rotate JBlock", "[Rotate]") {
    testBlockRotation<JBlock>("JBlock");
}

TEST_CASE("Rotate LBlock", "[Rotate]") {
    testBlockRotation<LBlock>("LBlock");
}

TEST_CASE("Rotate SBlock", "[Rotate]") {
    testBlockRotation<SBlock>("SBlock");
}

TEST_CASE("Rotate TBlock", "[Rotate]") {
    testBlockRotation<TBlock>("TBlock");
}

TEST_CASE("Rotate ZBlock", "[Rotate]") {
    testBlockRotation<ZBlock>("ZBlock");
}

TEST_CASE("OBlock rotation should do nothing", "[Rotate]") {
    OBlock block;
    auto original = block.GetCellPositions();

    block.Rotate();
    auto rotated = block.GetCellPositions();

    printPositions(original, "OBlock - Original");
    printPositions(rotated, "OBlock - After Rotate()");

    REQUIRE(original == rotated);
}
