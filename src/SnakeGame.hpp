#pragma once
#include <ncurses.h>
#include "Board.hpp"

class SnakeGame{
public:
    SnakeGame(int y,int x){
        board = Board(y,x);
        board.initialize();
        game_over = false;
    }

    void processInput(){
        chtype input = board.getInput();

    }
    void updateState(){
        
    }

    void redraw(){
        board.refresh();
    }

    bool isOver(){
        return this->game_over;
    }
private:
    Board board;
    bool game_over;
};