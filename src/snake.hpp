#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include <queue>

using namespace std;

enum Direction{
    up = -1,
    down = 1,
    left = -2,
    right = 2
};

class Snakepiece : public Drawable{
public:
    Snakepiece(){
        this->x = this->y = 0;
        this->icon = '#';
    }

    Snakepiece(int y, int x){
        this->x = x;
        this->y = y;
        this->icon = '#';
    }
};

class Snake{

    queue<Snakepiece> prev_pieces;
    Direction cur_direction;

public:
    Snake(){
        cur_direction = down;
    }
    void addPiece(Snakepiece piece){
        prev_pieces.push(piece);
    }
    void removePiece(){
        prev_pieces.pop();
    }
    Snakepiece tail(){
        return prev_pieces.back();
    }
    Snakepiece head(){
        return prev_pieces.front();
    }

    Direction getDirection(){
        return cur_direction;
    }
    void setDirection(Direction d){
        
        if (cur_direction + d != 0){
            cur_direction = d;
        }
        

    }

    Snakepiece nextHead(){
        int row = head().getY();
        int col = head().getX();

        switch(cur_direction){
            case down:
                row++;
                break;
            case up:
                row--;
                break;
            case left:
                col--;
                break;
            case right:
                col++;
                break;
            
        }
        return Snakepiece(row,col);
    }
};