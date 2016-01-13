# Makefile for Selling Out.

# Compiler and Flags.
CC=g++
CFLAGS=

all: share

share: share.cpp share.h ; $(CC) $(CFLAGS) -o share share.cpp

clean: ; rm share

# The End
