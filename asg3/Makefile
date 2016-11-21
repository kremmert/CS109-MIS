CC = g++
CFLAGS = -o
RM = rm -f
CLASSES = Server.cpp Var.cpp Parse.cpp Numeric.cpp String.cpp Real.cpp Char.cpp
CLASSESMATH = Math.cpp Add.cpp Sub.cpp Div.cpp Mul.cpp
CLASSES1 = Instructions.cpp Function.cpp Sleep.cpp Assign.cpp Out.cpp Thread.cpp
CLASSES2 = Set_Str_Char.cpp Get_Str_Char.cpp TCPSocket.cpp TCPServerSocket.cpp
CLIENTSTUFF = Client.cpp TCPSocket.cpp Parse.cpp

default: all

all : server client

server: $(CLASSES)
	$(CC) -std=c++14 -g -lpthread $(CLASSES) $(CLASSESMATH) $(CLASSES1) $(CLASSES2) $(CFLAGS) server

client: $(CLIENTSTUFF)
	$(CC) -std=c++14 -g -lpthread $(CLIENTSTUFF) $(CFLAGS) client
	
clean:
	$(RM) server client Output.out
