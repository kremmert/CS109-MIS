CC = g++
CFLAGS = -o
RM = rm -f

default: all

all : attendance inventory maxheap

attendance: problem1.cpp
	$(CC) -std=c++11 problem1.cpp $(CFLAGS) attendance

inventory: problem2.cpp
	$(CC) -std=c++11 problem2.cpp $(CFLAGS) invy

maxheap: problem3.cpp
	$(CC) -std=c++11 problem3.cpp $(CFLAGS)  max_heap

clean:
	$(RM) attendance invy max_heap
