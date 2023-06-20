all : main

main : main.cpp src/SnakeGame.hpp src/Board.hpp src/Drawable.hpp
	g++ main.cpp -lncurses -o main