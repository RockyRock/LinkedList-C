# Makefile
# This is a Makefile for the linked list project
# R. Guicherd - June 2020

# Compiler variables
CC = gcc
CFLAGS = -Wall -g

# Targets
main_exe: main.o linkedlist.o
	$(CC) $(CFLAGS) -o main_exe main.o linkedlist.o
	
main.o: main.c linkedlist.h
	$(CC) $(CFLAGS) -c main.c
	
linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c
	
# Clean rule
clean:
	$(RM) *.o main_exe