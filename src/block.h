#pragma once
#include <vector>
#include <map>
#include "colors.h"
#include "position.h"

class Block{
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> cells;
        void Draw(int offsetX, int offsetY);
        void Move(int x, int y);
        std::vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotate();

    private:
        int col_offset;
        int row_offset;
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
};