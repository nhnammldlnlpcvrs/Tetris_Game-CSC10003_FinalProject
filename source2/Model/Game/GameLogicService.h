#pragma once

#include "../source2/Model/Block/Block.h"
#include "../source2/Core/Grid/Grid.h"

class GameLogicService {
public:
    bool MoveLeft(Block& block, const Grid& grid) const;
    bool MoveRight(Block& block, const Grid& grid) const;
    bool MoveDown(Block& block, const Grid& grid) const;
    bool Rotate(Block& block, const Grid& grid) const;

    void LockBlock(Grid& grid, const Block& block) const;
    int ClearLines(Grid& grid) const;
    bool IsGameOver(const Grid& grid) const;
};

