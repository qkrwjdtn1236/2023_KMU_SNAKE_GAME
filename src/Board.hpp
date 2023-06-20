#pragma once
#include "Drawable.hpp"
#include <time.h>
#include <stdlib.h>
class Board{
public:
    Board(){
        this->construct(0,0);
    }
    Board(int height, int width){ 
        // 맵 생성하는데 필요한 처리

        construct(height,width);
    }
    
    void initialize(){
        clear();
        refresh();
    }
    void addBorder(){
        box(board_win,0,0);
    }
    void add(Drawable drawable){
        addAt(drawable.getX(),drawable.getY(),drawable.getIcon());
    }
    void addAt(int y, int x, chtype ch){
        mvwaddch(board_win,y,x,ch);
    }
    chtype getInput(){
        return wgetch(board_win);
    }
    void clear(){
        wclear(board_win);
        addBorder();
    }
    void refresh(){
        wrefresh(board_win);
    }
    

    // // map array clear
    // void clearBasicMap(){
    //     for(int i = 0;i<height;i++)
    //     {
    //         for(int j = 0;j<width;j++)
    //             this->mapArray[i][j]=0;
    //     }
    // }

    // // map init & set
    // void setBasicMap(int level = 1){
    //     switch(level){
    //         case 1: // basic map
    //             for(int i = 0;i<height;i++){
    //                 this->mapArray[i][0]+=1;
    //                 this->mapArray[i][width]+=1;
    //             }
    //             for(int i = 0;i<width;i++)
    //             {
    //                 this->mapArray[0][i]+=1;
    //                 this->mapArray[height][i]+=1;
    //             }
    //     }
    // }

    void getEmptyCoordinates(int &y,int &x){
        while(mvwinch(board_win,
                    y = rand()%this->height,
                    x=rand()%this->width) != ' ');
    }
    void setTimeout(int timeout){
        wtimeout(board_win,timeout);
    }
private:
    int mapArray[21][21] = {0,}; // map info
    WINDOW *board_win; // map object
    int height, width;

    void construct(int height, int width){
        int xMax, yMax;
        getmaxyx(stdscr,yMax,xMax);
        board_win = newwin(height,width, 
                        (yMax/2)-height / 2,(xMax/2)-width / 2);
        this->height = height;
        this->width = width;

        wtimeout(board_win,100);
        keypad(board_win,true);
    }
};