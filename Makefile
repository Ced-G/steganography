CC = gcc
CFLAGS  = -Wall

all:
	$(CC) $(CFLAGS) *.c -o lsb_steg

clean:
	rm -f lsb_steg