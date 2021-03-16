
CFLAGS = -Wall -std=c99

all: rules.d sed253

sed253: sed253.o
	gcc $(CFLAGS) sed253.c -o sed253

rules.d: $(wildcard *.c) $(wildcard *.h)
	gcc -MM $(wildcard *.c) >rules.d

-include rules.d

clean:
	rm -f *.o rules.d sed253