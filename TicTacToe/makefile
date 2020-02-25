output: main.o board.o manager.o tictactoe_Ai.o
	g++ main.o board.o manager.o tictactoe_Ai.o -o TicTacToe

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp lib/board.h
	g++ -c board.cpp

manager.o: manager.cpp lib/manager.h
	g++ -c manager.cpp

tictactoe_Ai.o: tictactoe_Ai.cpp lib/tictactoe_Ai.h
	g++ -c tictactoe_Ai.cpp
	
clean:
	rm *.o 