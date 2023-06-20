// #include <iostream>
#include <ncurses.h>
#include "src/Board.hpp"
#include "src/SnakeGame.hpp"
#include "src/Drawable.hpp"

#define BOARD_DIM 21
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

using namespace std;

int main(int argc, char **argv){
    initscr();              // Start curses mode
    refresh();              // Print it on to the real screen
    noecho();
    curs_set(0);
    ////

    // 화면 출력용
    SnakeGame game(BOARD_ROWS,BOARD_COLS);
    
    while(!game.isOver()){ // a lot case in gameover -> break;
        game.processInput();
        // get input user key

        game.updateState();
        // status update

        game.redraw();
        // update game map

    }
    

    ////
    getch();                // Wait for user input
    endwin();               // End curses mode
    return 0;
}