CXX = G++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++20

chess: main.o tile.o piece.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

tile.o: tile.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

piece.0: piece.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
clean:
	rm chess *.o
