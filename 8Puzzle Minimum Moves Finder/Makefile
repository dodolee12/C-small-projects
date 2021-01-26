#Edward Lee edl6zpg Makefile 11/16/2020
CXX = clang++

CXXFLAGS = -Wall -g -O2

OBJECTS =  8puzzle.o puzzlesolver.o


a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out
	doxygen

8puzzle.o: 8puzzle.cpp 8puzzle.h

puzzlesolver.o:puzzlesolver.cpp

.PHONY: clean

clean:
	-rm -f *.o *~
