CC = gcc
CFLAGS = -g -Wall

sort: sort_count.o
	$(CC) $(CFLAGS) -o sort sort_count.o
sort_count.o: sort_count.c
	$(CC) $(CFLAGS) -c sort_count.c
