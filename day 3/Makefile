IDIR=include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11 -fopenmp -O3

ODIR=src
LDIR =../lib

LIBS=-lm -fopenmp 

day_3.o:
	$(CXX) -c -o $@ day_3.cpp ${CXXFLAGS} 

day_3: $(OBJ) day_3.o
	$(CXX) -o $@ $^ $(LIBS)

all: clean day_3
.PHONY: clean

default: all 

.DEFAULT_GOAL := default

clean:
	rm -f *.o
