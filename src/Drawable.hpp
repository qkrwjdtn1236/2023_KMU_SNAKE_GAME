#pragma once
#include <ncurses.h>

class Drawable{
public:
    Drawable(){
        this->y = this->x = 0;
        this->icon = ' ';
    }
    Drawable(int y, int x, chtype ch){
        this->y = y;
        this->x = x;
        this->icon = ch;
    }
    int getX(){
        return this->x;
    }

    int getY(){
        return this->y;
    }
    chtype getIcon(){
        return icon;
    }
protected:
    int y,x;
    chtype icon;
};