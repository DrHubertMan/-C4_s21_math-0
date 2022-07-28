CC = gcc
CFLAGS = -Wall -Werror -Wextra -c 
OFLAGS = -Wall -Werror -Wextra -o
DFLAGS = -g


all:s21_math

s21_math: s21_math.o
	$(CC) $(OFLAGS) kek.out *.o

s21_math.o: s21_math.h
	$(CC) $(CFLAGS) $(DFLAGS) *.c

clean:
	rm -rf *.o *.out

rebuild: clean all