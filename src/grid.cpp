#include "grid.h"
#include <iostream>
#include <vector>
#include "colors.h"

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize(){
    for( int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            grid[row][col] = 0;
        }
    }
}

void Grid::Print(){
    for( int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            std::cout << grid[row][col] << " ";
        }
        std::cout << std:: endl;
    }
}

void Grid::Draw(){
    for( int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 10, row * cellSize + 10, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if(row >= 0 && row < numRows && column >= 0 && column < numCols)
        return false;
    return true;
}

bool Grid::isCellEmpty(int row, int column){
    if(grid[row][column] == 0)
        return true;
    return false;
}

void Grid::addToGrid(int row, int column, int value)
{
    grid[row][column] = value;
}

int Grid::ClearFullRows()
{
    int clearedRows = 0;
    for(int row = numRows -1; row >= 0; row--){
        if(isRowFull(row)){
            clearedRows++;
            ClearRow(row);
        }
        else if(clearedRows>0)
            MoveRowDown(row, clearedRows);
    }
    return clearedRows;
}

bool Grid::isRowFull(int row)
{
    for(int column = 0; column < numCols; column++){
        if(grid[row][column] == 0){
            return false;
        }
    }
    return true;
}

void Grid::MoveRowDown(int row, int rowsDown)
{
    for(int column = 0; column < numCols; column++){
        grid[row+rowsDown][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

void Grid::ClearRow(int row)
{
    for(int column = 0; column < numCols; column++){
        grid[row][column] = 0;
    }
}
