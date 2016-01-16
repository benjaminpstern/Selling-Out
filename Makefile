# Makefile for Selling Out.

# Compiler and Flags.
CC=g++
CFLAGS=-g -std=c++11

all: share player

share: share.cpp share.h ; $(CC) $(CFLAGS) -c -o share share.cpp

player: player.cpp player.h ; $(CC) $(CFLAGS) -c -o player player.cpp

clean: ; rm share

# The End
