#include "GameLogicService.h"
#include "../source2/Core/Graphics/Color.h"

bool GameLogicService::MoveLeft(Block& block, const Grid& grid) const {
    block.MoveLeft();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.MoveRight();
        return false;
    }
    return true;
}

bool GameLogicService::MoveRight(Block& block, const Grid& grid) const {
    block.MoveRight();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.MoveLeft();
        return false;
    }
    return true;
}

bool GameLogicService::MoveDown(Block& block, const Grid& grid) const {
    block.MoveDown();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.MoveUp();
        return false;
    }
    return true;
}

bool GameLogicService::Rotate(Block& block, const Grid& grid) const {
    block.Rotate();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.RotateBack();
        return false;
    }
    return true;
}

void GameLogicService::LockBlock(Grid& grid, const Block& block) const {
    const auto& positions = block.GetCellPositions();
    const auto& colors = block.GetCellColor();

    for (size_t i = 0; i < positions.size(); ++i) {
        grid.SetCell(positions[i].row, positions[i].column, colors[i]);
    }
}

int GameLogicService::ClearLines(Grid& grid) const {
    return grid.ClearFullLines();
}

bool GameLogicService::IsGameOver(const Grid& grid) const {
    return grid.HasBlockAtTop();
}
