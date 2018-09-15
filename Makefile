#Args
CC=g++
SRCS= game.cpp utils.cpp main.cpp
OBJS= $(SRCS:%.cpp=%.o)
FLAGS= -c -Wall -g
EXEC= teste
VFLAGS= --leak-check=full
.PHONY=compile

#commands
all: compile
	$(CC) $(OBJS) -g -o3 -o $(EXEC)

compile:
	$(CC) $(FLAGS) $(SRCS)

run:
	./$(EXEC)

test: all
	valgrind ./$(EXEC) $(VFLAGS)


clean:
	rm $(OBJS) $(EXEC)
