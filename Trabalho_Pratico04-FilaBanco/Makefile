CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: banco

banco: banco.o queue.o
	$(CC) $(CFLAGS) -o banco banco.o queue.o

banco.o: banco.c queue.h
	$(CC) $(CFLAGS) -c banco.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o banco