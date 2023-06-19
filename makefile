all : main

main : main.cpp src/SnakeGame.hpp src/Board.hpp
	g++ main.cpp -lncurses -o main