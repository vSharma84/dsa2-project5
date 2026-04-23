CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

OBJS = main.o LCSSolver.o SimilarityTable.o

project5 : $(OBJS)
	$(CXX) $(CXXFLAGS) -o project5 $(OBJS)

main.o : main.cpp LCSSolver.h SimilarityTable.h
	$(CXX) $(CXXFLAGS) -c main.cpp

LCSSolver.o : LCSSolver.cpp LCSSolver.h
	$(CXX) $(CXXFLAGS) -c LCSSolver.cpp

SimilarityTable.o : SimilarityTable.cpp SimilarityTable.h LCSSolver.h
	$(CXX) $(CXXFLAGS) -c SimilarityTable.cpp

clean:
	rm -f *.o project5