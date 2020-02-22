output: main.o board.o manager.o
	g++ main.o board.o manager.o -o TicTacToe

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp lib/board.h
	g++ -c board.cpp

manager.o: manager.cpp lib/manager.h
	g++ -c manager.cpp
	
clean:
	rm *.o 