clang:
	clang++ -Wall  -W -o Monopoly src/*.cpp -I ./include -l:libncurses.a
gcc:
	g++ -Wall  -W -o Monopoly src/*.cpp -I ./include -l:libncurses.a

