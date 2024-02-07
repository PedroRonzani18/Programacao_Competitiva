CXX = g++
CṔXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

q:
	cp temp.cpp $(f).cpp
	touch $(f).txt
	code $(f).txt	
	code $(f).cpp
	clear

compile: 
	g++ -g $(f).cpp $(CXXFLAGS) -o $(f)

exe:
	./$(f) < $(f).txt

runc: compile exec

runci: compile
	./$(f) < $(f).txt

clearexe:
	find . -maxdepth 1 -type f -executable -exec rm {} +

cleartxt:
	find . -type f -name "*.txt" -exec rm -f {} \; 

clear: clearexe cleartxt
	clear

runp:
	python3 $(f).py

runpt:
	python3 $(f).py < $(f).txt