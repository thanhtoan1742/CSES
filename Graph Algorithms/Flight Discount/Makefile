console: main 
	./main

file: main 
	./main < input.txt > output.txt

filein: main
	./main < input.txt

main: main.cpp 
	g++ -g -O2 -Wall -std=gnu++17 -static main.cpp -o main
