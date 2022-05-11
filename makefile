CC=gcc
CFLAGS=-g -I.

hrc_test: hrc_test.o hrc.o hrc.h
	$(CC) -o test hrc_test.o hrc.o



