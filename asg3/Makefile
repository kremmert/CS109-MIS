CC = g++
CFLAGS = -o
RM = rm -f
CLASSES = Server.cpp Var.cpp Parse.cpp Numeric.cpp String.cpp Real.cpp Char.cpp
CLASSESMATH = Math.cpp Add.cpp Sub.cpp Div.cpp Mul.cpp
CLASSES1 = Instructions.cpp 

default: all

all : server

server: $(CLASSES)
	$(CC) -std=c++11 $(CLASSES) $(CLASSESMATH) $(CLASSES1) $(CFLAGS) server

clean:
	$(RM) server
