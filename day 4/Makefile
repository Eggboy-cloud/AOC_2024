IDIR=include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11 -fopenmp -O3

ODIR=src
LDIR =../lib

LIBS=-lm -fopenmp 

day_4.o:
	$(CXX) -c -o $@ day_4.cpp ${CXXFLAGS} 

day_4: $(OBJ) day_4.o
	$(CXX) -o $@ $^ $(LIBS)

all: clean day_4
.PHONY: clean

default: all 

.DEFAULT_GOAL := default

clean:
	rm -f *.o
