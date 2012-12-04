all:
	clang++ -Wall  -W -static -o Monopoly src/*.cpp -I ./include -lncurses

