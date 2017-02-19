all :
	g++ lexer.cpp main.cpp Automate.cpp Etats.cpp -o analyse
	
debug :
	g++ -g lexer.cpp main.cpp -o analyse
