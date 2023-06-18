#pragma once

class Board{
public:
    Board(int height, int width){ // 맵 생성하는데 필요한 처리
        int xMax,yMax;
        getmaxyx(stdscr,yMax,xMax); // terminal size get
        
        // board map create
        WINDOW *board_win = newwin(height,width, 
                        (yMax/2)-height / 2,(xMax/2)-width / 2);
        
        // board show
        box(board_win,0,0);
        wrefresh(board_win);

        // board size info
        this->width = width;
        this->height = height;

        this->setBasicMap();
    }
    // add boardLevel(optinal)
    Board(int height, int width,int level){
        Board(height,width);
        setBasicMap(level);
    }

    // map array clear
    void clearBasicMap(){
        for(int i = 0;i<height;i++)
        {
            for(int j = 0;j<width;j++)
                this->mapArray[i][j]=0;
        }
    }

    // map init & set
    void setBasicMap(int level = 1){
        switch(level){
            case 1: // basic map
                for(int i = 0;i<height;i++){
                    this->mapArray[i][0]+=1;
                    this->mapArray[i][width]+=1;
                }
                for(int i = 0;i<width;i++)
                {
                    this->mapArray[0][i]+=1;
                    this->mapArray[height][i]+=1;
                }
        }
    }
private:
    int mapArray[21][21] = {0,}; // map info
    WINDOW *board_win; // map object
    int height, width;
};