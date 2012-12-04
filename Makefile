clang:
	clang++ -Wall  -W -static -o Monopoly src/*.cpp -I ./include -lncurses
gcc:
	g++ -Wall  -W -static -o Monopoly src/*.cpp -I ./include -lncurses

