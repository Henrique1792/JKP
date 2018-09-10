#Args
CC=g++
SRCS= game.cpp utils.cpp main.cpp
OBJS= $(SRCS:%.cpp=%.o)
FLAGS= -c -Wall
EXEC= teste
.PHONY=compile

#commands
all: compile
	$(CC) $(OBJS) -o3 -o $(EXEC)

compile:
	$(CC) $(FLAGS) $(SRCS)

run:
	./$(EXEC)
clean:
	rm $(OBJS) $(EXEC)
