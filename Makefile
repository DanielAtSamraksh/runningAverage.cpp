

all: testa

testa: test.cpp runningAverage.h Makefile
	g++ test.cpp -o testa
	./testa 1 2 3 4 5 6 7
