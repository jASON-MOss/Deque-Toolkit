CC = g++
CFLAGS = -g -Wall -Wextra


default: deque


deque:deque.o main.o
	$(CC) $(CFlags) -o deque deque.o main.o


deque.o:deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp


main.o:	main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp


clean:
	$(RM) deque *.o *~
