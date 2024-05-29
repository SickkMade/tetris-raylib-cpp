#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        Game();
        Grid grid;
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;

    private:
        void MoveBlockLeft();
        void MoveBlockRight();
        
        void PlaceBlock();
        bool IsBlockInvalid();
        std::vector<Block> blocks;
        Block GetRandomBlock();
        std::vector<Block> GetFullBlocks();
        void Reset();
        Block currentBlock;
        Block nextBlock;
        void RotateBlock();
};