#pragma once
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <memory>
#include "raylib.h"
#include "Core/Position/Position.h"
#include "Core/Graphics/Color.h"
#include "BlockMemento.h"

class Block {
public:
    Block();

    std::shared_ptr<BlockMemento> SaveState() const;
    void RestoreState(const std::shared_ptr<BlockMemento>& memento);

    void Draw(int offset_x, int offset_y);
    void DrawPreview(int offset_x, int offset_y);
    void Move(int rows, int columns);
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void MoveUp();

    void Rotate();
    void RotateBack();

    std::vector<Position> GetCellPositions() const;
    std::pair<int, int> GetSize() const;
    int GetId() const;
    virtual std::vector<Color> GetCellColor() const = 0;

    virtual std::unique_ptr<Block> Clone() const = 0;
    virtual ~Block() = default;

protected:
    static constexpr int cellSize = 30;

    int _id;
    int _rotationState;
    int _rowOffset;
    int _columnOffset;

    std::map<int, std::vector<Position>> _cells;
    std::vector<Color> _colors;
};
