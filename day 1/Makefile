IDIR=include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11 -fopenmp -O3

ODIR=src
LDIR =../lib

LIBS=-lm -fopenmp 


nnetwork_mpi.o:
	$(MPICXX) -c -o $@ nnetwork.cxx ${CXXFLAGS} -DUSE_MPI

day_1.o:
	$(CXX) -c -o $@ day_1.cxx ${CXXFLAGS} 

day_1: $(OBJ) day_1.o
	$(CXX) -o $@ $^ $(LIBS)

all: clean day_1
.PHONY: clean

default: clean all 

.DEFAULT_GOAL := default

clean:
	rm -f *.o
