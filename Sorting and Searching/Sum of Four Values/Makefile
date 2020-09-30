default: main 
	./main

file: main 
	./main < input.txt > output.txt
	
main: main.cpp 
	g++ -g -O2 -std=gnu++17 -static main.cpp -o main