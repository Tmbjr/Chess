CXX = G++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++20

chess: main.o tile.o piece.o movement.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

tile.o: tile.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

piece.o: piece.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

movement.o: movement.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
clean:
	rm chess *.o
