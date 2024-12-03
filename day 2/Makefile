IDIR=include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11 -fopenmp -O3

ODIR=src
LDIR =../lib

LIBS=-lm -fopenmp 

day_2.o:
	$(CXX) -c -o $@ day_2.cpp ${CXXFLAGS} 

day_2: $(OBJ) day_2.o
	$(CXX) -o $@ $^ $(LIBS)

all: clean day_2
.PHONY: clean

default: all 

.DEFAULT_GOAL := default

clean:
	rm -f *.o
