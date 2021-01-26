#Edward Lee edl6zpg Makefile 11/8/2020

CXX = clang++

CXXFLAGS = -Wall -g




OBJECTS1 = huffmandec.o HuffmanNode.o
OBJECTS2 = HuffmanNode.o heap.o huffmanenc.o

all: decoder encoder

decoder: $(OBJECTS1)
	$(CXX) $(CXXFLAGS) $(OBJECTS1) -o decoder

encoder: $(OBJECTS2)
	$(CXX) $(CXXFLAGS) $(OBJECTS2) -o encoder

huffmandec.o:huffmandec.cpp

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h

heap.o: heap.h heap.cpp

huffmanenc.o: huffmanenc.cpp

.PHONY: clean

clean:
	-rm -f *.o *~
