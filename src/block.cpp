#include "block.h"

Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    row_offset= 0;
    col_offset = 0;
}

void Block::Draw(int offsetX, int offsetY){
    std::vector<Position> tiles = GetCellPositions();

    for(Position pos: tiles){
        DrawRectangle(pos.column * cellSize + offsetX, pos.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns){
    row_offset += rows;
    col_offset += columns;
}

std::vector<Position> Block::GetCellPositions(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for(Position pos: tiles){
        Position newPos = Position(pos.row + row_offset, pos.column + col_offset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState += 1;
    if(rotationState >= (int)cells.size())
        rotationState = 0;
}

void Block::UndoRotate(){
    rotationState -= 1;
    if(rotationState < 0)
        rotationState = cells.size()-1;
}
