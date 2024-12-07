IDIR=include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11 -fopenmp -O3

ODIR=src
LDIR =../lib

LIBS=-lm -fopenmp 

day_5.o:
	$(CXX) -c -o $@ day_5.cpp ${CXXFLAGS} 

day_5: $(OBJ) day_5.o
	$(CXX) -o $@ $^ $(LIBS)

all: clean day_5
.PHONY: clean

default: all 

.DEFAULT_GOAL := default

clean:
	rm -f *.o
