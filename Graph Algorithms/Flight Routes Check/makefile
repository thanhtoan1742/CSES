run: main
	./main

filein: main
	./main < input.txt

fileout: main
	./main > output.txt

file: main
	./main < input.txt > output.txt

main: main.cpp
	g++ -std=gnu++17 -Wall -O2 main.cpp -o main