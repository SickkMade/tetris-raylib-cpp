#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
        void Initialize();
        Grid();
        void Print();
        void Draw();
        bool isCellOutside(int row, int column);
        bool isCellEmpty(int row, int column);
        int grid[20][10];
        void addToGrid(int row, int col, int value);
        int ClearFullRows();
    private:
        bool isRowFull(int row);
        void MoveRowDown(int row, int rowsDown);
        void ClearRow(int row);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};