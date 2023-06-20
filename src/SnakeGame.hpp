#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include "snake.hpp"
#include "Empty.hpp"

class SnakeGame{
public:
    SnakeGame(int y,int x){
        board = Board(y,x);
        this->initialize();
    }

    void processInput(){
        chtype input = board.getInput();

    }
    void updateState(){
        // 

        // board.add(Drawable(3,3,'#'));
        if(apple == NULL){
            int x,y;
            board.getEmptyCoordinates(y,x);
            // board.add(Empty(apple->getY(), apple->getX()));
        
            apple = new Apple(y,x);
            board.add(*apple);
        }
        Snakepiece next = snake.nextHead();
        if(next.getX() != apple->getX() && next.getY() != apple->getY()){
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow,emptyCol));
            snake.removePiece();
        }
        board.add(next);
        snake.addPiece(next);
    }

    void redraw(){
        board.refresh();
    }

    bool isOver(){
        return this->game_over;
    }

    void initialize(){
        apple = NULL;
        board.initialize();
        game_over = false;
        srand(time(NULL));

        snake.setDirection(down);

        Snakepiece next = Snakepiece(1,1);
        board.add(next);
        snake.addPiece(next);

        next = snake.nextHead();
        board.add(next);
        snake.addPiece(next);
        

        next = snake.nextHead();
        board.add(next);
        snake.addPiece(next);
        
        snake.setDirection(right);
        
        next = snake.nextHead();
        board.add(next);
        snake.addPiece(next);
        

    }
private:
    Board board;
    bool game_over;
    Apple *apple;
    Snake snake;
};