#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetFullBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score=0;
}

bool Game::IsBlockInvalid()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position pos: tiles){
        if(grid.isCellOutside(pos.row, pos.column)){
            return true;
        }
        if(!grid.isCellEmpty(pos.row, pos.column)){
            return true;
        }
    }
    return false;
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
        blocks = GetFullBlocks();
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetFullBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Reset()
{
    blocks = GetFullBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    grid.Initialize();
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw(10, 10);
    nextBlock.Draw(270,270);
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(gameOver){
        if(keyPressed != 0){
            gameOver = false;
            Reset();
        }    
        else{
            return;
        } 
    }
        
    
    switch(keyPressed){
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

void Game::MoveBlockLeft(){
    currentBlock.Move(0, -1);
    if(IsBlockInvalid()){
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight(){
    currentBlock.Move(0, 1);
    if(IsBlockInvalid()){
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown(){
    if(gameOver)
        return;
    currentBlock.Move(1, 0);
    if(IsBlockInvalid()){
        currentBlock.Move(-1,0);
        PlaceBlock();
    }
}

void Game::PlaceBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position pos: tiles){
        grid.addToGrid(pos.row, pos.column, currentBlock.id);
    }

    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();

    if(IsBlockInvalid()){
        //game over
        gameOver = true;
    }

    score += grid.ClearFullRows() * 100;
}

void Game::RotateBlock(){
    currentBlock.Rotate();
    if(IsBlockInvalid()){
        currentBlock.UndoRotate();
    }
}