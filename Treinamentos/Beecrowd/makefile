CXX = g++
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

compile: 
	g++ -g $(f).cpp $(CXXFLAGS) -o $(f)

exec:
	./$(f)

runc: compile exec

runci: compile
	./$(f) < $(f).txt

clearexe:
	find . -maxdepth 1 -type f -executable -exec rm {} +

cleartxt:
	find . -type f -name "*.txt" -exec rm -f {} \; 

clear: clearexe cleartxt

runp:
	python3 $(f).py

runpt:
	python3 $(f).py < $(f).txt