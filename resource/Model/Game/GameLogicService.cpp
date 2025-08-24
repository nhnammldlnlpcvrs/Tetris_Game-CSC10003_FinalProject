#include "GameLogicService.h"

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
    std::vector<Color> colors = block.GetCellColor();

    // Nếu chỉ có 1 màu, nhân bản màu để match số cell
    if (colors.size() == 1 && positions.size() > 1) {
        colors = std::vector<Color>(positions.size(), colors[0]);
    }

    // Nếu mismatch, throw để phát hiện lỗi sớm
    if (positions.size() != colors.size()) {
        throw std::runtime_error("LockBlock error: positions.size() != colors.size()");
    }

    for (size_t i = 0; i < positions.size(); ++i) {
        const auto& pos = positions[i];
        if (pos.row >= 0 && pos.row < grid.GetRows() &&
            pos.column >= 0 && pos.column < grid.GetColumns()) {
            grid.SetCell(pos.row, pos.column, colors[i]);
        } else {
            // Log hoặc bỏ qua nếu vị trí ngoài grid
        }
    }
}


int GameLogicService::ClearLines(Grid& grid) const {
    return grid.ClearFullLines();
}

bool GameLogicService::IsGameOver(const Grid& grid) const {
    return grid.HasBlockAtTop();
}
