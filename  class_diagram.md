classDiagram
%% Extended clean version for mermaid.live with concrete tetromino classes

%% App
class App {
  +Run()
}

%% Controllers
class BlockController {
  +BlockController(block)
  +Move(delta_row, delta_col)
  +Rotate()
  +GetBlock()
  +SaveState()
  +Undo()
  +Redo()
  -block_
  -history_
}

class GameController {
  +GameController(rows, cols, cellSize)
  +Init()
  +Update(deltaTime)
  +Draw()
  +DrawNextBlock()
  +Reset()
  +GetScore()
  +GetBestScore()
  +IsGameOver()
  -grid_
  -current_block_
  -next_block_
  -renderer_
  -logic_
  -score_
  -audio_
  -drop_timer_
  -drop_interval_
  -is_game_over_
  -SpawnNewBlock()
}

%% Model.Block (abstract base)
class Block {
  +Block()
  +SaveState()
  +RestoreState(memento)
  +Draw(offset_x, offset_y)
  +DrawPreview(offset_x, offset_y)
  +Move(rows, columns)
  +MoveLeft()
  +MoveRight()
  +MoveDown()
  +MoveUp()
  +Rotate()
  +RotateBack()
  +GetCellPositions()
  +GetSize()
  +GetId()
  +GetCellColor() <<abstract>>
  +Clone() <<abstract>>
  -id_
  -rotationState_
  -rowOffset_
  -columnOffset_
  -cells_
  -colors_
}

class IBlock {
  +IBlock()
  +GetCellColor()
  +Clone()
}

class JBlock {
  +JBlock()
  +GetCellColor()
  +Clone()
}

class TBlock {
  +TBlock()
  +GetCellColor()
  +Clone()
}

class ZBlock {
  +ZBlock()
  +GetCellColor()
  +Clone()
}

class OBlock {
  +OBlock()
  +GetCellColor()
  +Clone()
}

class LBlock {
  +LBlock()
  +GetCellColor()
  +Clone()
}

class SBlock {
  +SBlock()
  +GetCellColor()
  +Clone()
}

%% Memento / History
class IMemento {
  +~IMemento()
}

class BlockMemento {
  +BlockMemento(rotationState, rowOffset, columnOffset)
  +GetRotationState()
  +GetRowOffset()
  +GetColumnOffset()
  -rotationState_
  -rowOffset_
  -columnOffset_
}

class BlockHistory {
  +Save(memento)
  +Undo()
  +Redo()
  +CanUndo()
  +CanRedo()
  +Clear()
  -undo_stack_
  -redo_stack_
}

%% Factory / Generators / Services
class BlockFactory {
  +BlockFactory()
  +CreateBlock(id)
  +CreateRandomBlock()
  -prototypes_
  -GenerateRandomId()
}

class RandomBlockGenerator {
  +Generate(gridColumns)
}

class GameLogicService {
  +MoveLeft(block, grid)
  +MoveRight(block, grid)
  +MoveDown(block, grid)
  +Rotate(block, grid)
  +LockBlock(grid, block)
  +ClearLines(grid)
  +IsGameOver(grid)
}

class ScoreService {
  +add_lines(n)
  +get_score()
  +Reset()
  +AddScore(linesCleared, dropPoints)
  +LoadBestScore()
  +SaveBestScore()
}

class AudioService {
  +Init()
  +PlayRotateEffect()
  +PlayClearEffect()
  +PlayBackgroundMusic()
  +GetBackgroundMusic()
}

%% Views / Renderers / Grid / Core
class BlockView {
  +Render(block, offset_x, offset_y)
}

class GridRenderer {
  +GridRenderer(cellSize)
  +Draw(grid, offset_x, offset_y)
  -cellSize_
}

class Grid {
  +Grid(rows, columns)
  +IsCellOccupied(row, column)
  +SetCell(row, column, color)
  +ClearCell(row, column)
  +ClearFullLines()
  +GetRows()
  +GetColumns()
  +GetCells()
  +IsValidPosition(positions)
  +HasBlockAtTop()
  -rows_
  -columns_
  -cells_
}

class Position
class Color

class AudioTypes
class Guide
class RandomBlockProvider

%% Inheritance / Implementation
Block <|-- IBlock
Block <|-- JBlock
Block <|-- TBlock
Block <|-- ZBlock
Block <|-- OBlock
Block <|-- LBlock
Block <|-- SBlock

IMemento <|.. BlockMemento

%% Associations / Uses
App --> GameController
GameController ..> Grid
GameController ..> GridRenderer
GameController ..> GameLogicService
GameController ..> ScoreService
GameController ..> AudioService
GameController ..> BlockFactory
GameController ..> RandomBlockGenerator
GameController ..> Block

BlockController --> Block
BlockController o-- BlockHistory
BlockController ..> BlockView

Block ..> BlockMemento
BlockHistory o-- BlockMemento

BlockFactory ..> Block
RandomBlockGenerator ..> Block

GridRenderer ..> Grid
BlockView ..> Block
ScoreService ..> GameLogicService
