CC = g++

SRCS = $(wildcard src/*.cpp)
INCLUDE = $(wildcard include/*.h)
OBJS=$(SRCS:.c=.o)


output: $(OBJS) main.o
	$(CC) $(OBJS) main.o -o output

main.o: main.cpp 
	$(CC) -c main.cpp

algorithm.o: $(SRC) $(INCLUDE)
	$(CC) -c $(SRC)


.PHONY = all clean

clean:
	rm *.o output