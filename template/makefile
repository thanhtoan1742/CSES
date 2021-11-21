run: main
	./main

file: main input.txt
	./main < input.txt > output.txt

filein: main input.txt
	./main < input.txt

fileout: main
	./main > output.txt

main: main.cpp
	g++ -std=c++17 - O2 -Wall main.cpp -o main
