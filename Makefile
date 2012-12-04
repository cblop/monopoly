clang:
	clang++ -Wall  -W -DNCURSES_STATIC -o Monopoly src/*.cpp -I ./include -static -l:libncurses.a
gcc:
	g++ -Wall  -W -DNCURSES_STATIC -o Monopoly src/*.cpp -I ./include -static -l:libncurses.a

