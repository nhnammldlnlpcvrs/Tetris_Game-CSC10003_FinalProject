#include "Color.h"

// màu nền (id=0)
const Color darkGrey = { 26, 31, 40, 255 };

// 7 màu chuẩn cho 7 khối
const Color cyan   = { 21, 204, 209, 255 }; // I
const Color blue   = { 13, 64, 216, 255 };  // J
const Color orange = { 226, 116, 17, 255 }; // L
const Color yellow = { 237, 234, 4, 255 };  // O
const Color green  = { 47, 230, 23, 255 };  // S
const Color purple = { 166, 0, 247, 255 };  // T
const Color red    = { 232, 18, 18, 255 };  // Z

std::vector<Color> GetCellColors()
{
    return { darkGrey, cyan, blue, orange, yellow, green, purple, red };
}

Color GetBlockColor(int id) {
    auto colors = GetCellColors();
    if (id >= 0 && id < (int)colors.size()) {
        return colors[id];
    }
    return BLACK;
}