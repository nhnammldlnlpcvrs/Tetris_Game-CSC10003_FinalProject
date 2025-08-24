#include "Block.h"


Block::Block() : _id(0), _rotationState(0), _rowOffset(0), _columnOffset(0) {}

std::shared_ptr<BlockMemento> Block::SaveState() const {
    return std::make_shared<BlockMemento>(_rotationState, _rowOffset, _columnOffset);
}

void Block::RestoreState(const std::shared_ptr<BlockMemento>& memento) {
    _rotationState = memento->GetRotationState();
    _rowOffset = memento->GetRowOffset();
    _columnOffset = memento->GetColumnOffset();
}

void Block::Draw(int offset_x, int offset_y) {
    auto positions = GetCellPositions();
    for (size_t i = 0; i < positions.size(); ++i) {
        DrawRectangle(
            offset_x + positions[i].column * cellSize,
            offset_y + positions[i].row * cellSize,
            cellSize - 1, cellSize - 1,
            _colors[i % _colors.size()]
        );
    }
}
void Block::DrawPreview(int offset_x, int offset_y) {
    auto positions = GetCellPositions();

    // Tìm giới hạn nhỏ nhất theo row và column
    int minRow = INT_MAX, minCol = INT_MAX;
    for (const auto& pos : positions) {
        if (pos.row < minRow) minRow = pos.row;
        if (pos.column < minCol) minCol = pos.column;
    }

    // Dịch khối về góc trái để hiển thị đúng
    for (size_t i = 0; i < positions.size(); ++i) {
        DrawRectangle(
            offset_x + (positions[i].column - minCol) * cellSize,
            offset_y + (positions[i].row - minRow) * cellSize,
            cellSize - 1, cellSize - 1,
            _colors[i % _colors.size()]
        );
    }
}
void Block::Move(int rows, int columns) {
    _rowOffset += rows;
    _columnOffset += columns;
}

void Block::MoveLeft() {
    _columnOffset--;
}

void Block::MoveRight() {
    _columnOffset++;
}

void Block::MoveDown() {
    _rowOffset++;
}

void Block::MoveUp() {
    _rowOffset--;
}

void Block::Rotate() {
    _rotationState = (_rotationState + 1) % 4;
}

void Block::RotateBack() {
    _rotationState = (_rotationState + 3) % 4;
}

std::vector<Position> Block::GetCellPositions() const {
    std::vector<Position> positions;
    for (const auto& pos : _cells.at(_rotationState)) {
        positions.push_back(Position{ _rowOffset + pos.row, _columnOffset + pos.column });
    }
    return positions;
}

std::pair<int, int> Block::GetSize() const {
    return { _rowOffset, _columnOffset };
}

int Block::GetId() const {
    return _id;
}

//std::vector<Color> Block::GetCellColor() const {
// return _colors;
//}
