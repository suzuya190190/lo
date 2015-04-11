#==========================================
#Make File 
#copyright keisue yamagishi  ($_$).oO 
#==========================================

CC=gcc
CFLAGS=-O

lol: lo.c lo.h
	$(CC) $(CFLAGS) -o lo lo.c -lncurses
