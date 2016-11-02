CC = g++
CFLAGS = -o
RM = rm -f


default: all

all: Hello

Hello: main.cpp
	$(CC) main.cpp $(CFLAGS) Hello

clean:
	$(RM) Hello
