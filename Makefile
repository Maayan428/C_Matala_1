
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
INCLUDES = -Isrc
SRC = src
TARGET = Main
TEST_TARGET = Test

SOURCES = $(SRC)/main.cpp \
          $(SRC)/Graph.cpp \
          $(SRC)/NeighborList.cpp \
          $(SRC)/Algorithms.cpp \
          $(SRC)/Queue.cpp \
          $(SRC)/Stack.cpp \
          $(SRC)/PriorityQueue.cpp \
          $(SRC)/UnionFind.cpp


.PHONY: all Main test valgrind clean

all: Main

Main: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(SOURCES)

test:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TEST_TARGET) $(SRC)/tests.cpp $(filter-out $(SRC)/main.cpp, $(SOURCES))

valgrind: Main
	valgrind ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)