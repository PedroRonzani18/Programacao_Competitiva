CXX = g++
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

clearexe:
	find . -maxdepth 1 -type f -executable -exec rm {} +

cleartxt:
	find . -type f -name "*.txt" -exec rm -f {} \; 

runc:
	g++ -g $(f).cpp $(CXXFLAGS) -o $(f)
	./$(f)

runci:
	g++ -g $(f).cpp $(CPPFLAGS) -o $(f)
	./$(f) < $(f).txt

runp:
	python3 $(f).py

runpt:
	python3 $(f).py < $(f).txt