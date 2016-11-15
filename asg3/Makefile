CC = g++
CFLAGS = -o
RM = rm -f
CLASSES = Server.cpp Var.cpp Parse.cpp Numeric.cpp String.cpp Real.cpp Char.cpp
CLASSESMATH = Math.cpp Add.cpp Sub.cpp Div.cpp Mul.cpp
CLASSES1 = Instructions.cpp Function.cpp Sleep.cpp Assign.cpp Out.cpp
CLASSES2 = Set_Str_Char.cpp Get_Str_Char.cpp 

default: all

all : server

server: $(CLASSES)
	$(CC) -std=c++14 -g $(CLASSES) $(CLASSESMATH) $(CLASSES1) $(CLASSES2) $(CFLAGS) server

clean:
	$(RM) server
