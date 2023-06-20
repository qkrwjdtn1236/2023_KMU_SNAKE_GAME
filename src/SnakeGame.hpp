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
        // printw("done init");
    }

    void processInput(){
        chtype input = board.getInput();

        switch(input){
            case KEY_UP:
            case 'w':
                snake.setDirection(up);
                break;
            case KEY_DOWN:
            case 's':
                snake.setDirection(down);
                break;
            case KEY_RIGHT:
            case 'd':
                snake.setDirection(right);
                break;
            case KEY_LEFT:
            case 'a':
                snake.setDirection(left);
                break;
            case 'p':
                board.setTimeout(-1);
                while(board.getInput() != 'p');
                board.setTimeout(100);
            default:
                break;

        }

    }
    void updateState(){
        // printw("done init");
        handleNextPiece(snake.nextHead());
        if(apple == NULL)
        {
            createApple();
        }
        
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

        snake.setDirection(right);
        handleNextPiece(Snakepiece(5,5));
        handleNextPiece(snake.nextHead());
        handleNextPiece(snake.nextHead());
        // snake.setDirection(right);
        if(apple == NULL)
            createApple();
    }

    void handleNextPiece(Snakepiece next){
        if(apple != NULL && (next.getX() != apple->getX() || next.getY() != apple->getY())){
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow,emptyCol));
            snake.removePiece();
        }else{
            destroyApple();
        }

        board.add(next);
        snake.addPiece(next);
    }

    void createApple(){
        if(apple == NULL){
            int x,y;
            board.getEmptyCoordinates(y,x);
            apple = new Apple(y,x);
            board.add(*apple);
        }
    }

    void destroyApple(){
        delete apple;
        apple = NULL;
    }
private:
    Board board;
    bool game_over;
    Apple *apple;
    Snake snake;
};