#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include <time.h>
#include <stdlib.h>


class SnakeGame{
public:
    SnakeGame(int y,int x){
        board = Board(y,x);
        board.initialize();
        game_over = false;
        srand(time(NULL));
    }

    void processInput(){
        chtype input = board.getInput();

    }
    void updateState(){
        int x,y;

        board.add(Drawable(3,3,'#'));
        board.getEmptyCoordinates(y,x);
        board.add(Apple(y,x));
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