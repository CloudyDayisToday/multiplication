CC = g++

output: main.o multiplication.o
	$(CC) main.o multiplication.o -o output

main.o: main.cpp
	$(CC) -c main.cpp

multiplication.o: multiplication.cpp multiplication.h
	$(CC) -c multiplication.cpp


.PHONY = all clean

clean:
	rm *.o output