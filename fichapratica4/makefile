#makefile para programa vowels_v2

OBJS = main.o string_utils.o
CFLAGS = -std=c11 -Wall -Wextra -g


vowels_v:$(OBJS)
	$(CC) -o $@ $^

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c

string_utils.o:string_utils.c string_utils.h
	$(CC) $(CFLAGS) -c string_utils.c

clean:
	rm *.o $(PROG) 2> /dev/null
