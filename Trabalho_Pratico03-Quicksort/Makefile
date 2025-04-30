CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = quicksort
OBJS = main.o stack.o quicksort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c stack.h quicksort.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

quicksort.o: quicksort.c quicksort.h stack.h
	$(CC) $(CFLAGS) -c quicksort.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean