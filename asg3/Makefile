CC = g++
CFLAGS = -o
RM = rm -f
CLASSES = Server.cpp var.cpp parse.cpp Numeric.cpp String.cpp Real.cpp Char.cpp
default: all

all : server

server: $(CLASSES)
	$(CC) -std=c++11 $(CLASSES) $(CFLAGS) server

clean:
	$(RM) server
