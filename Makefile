# Makefile for Selling Out.

# Compiler and Flags.
CC=clang++
CFLAGS=-g -std=c++11

TARGETS=share.o player.o management.o runTests
all: $(TARGETS)

share.o: share.cpp share.h ; $(CC) $(CFLAGS) -c share.cpp

player.o: player.cpp player.h ; $(CC) $(CFLAGS) -c  player.cpp

runTests: share.o player.o libgmock.a tests.cpp ; $(CC) -isystem ${GTEST_DIR}/include -pthread -isystem /usr/src/googletest-master/googlemock/include/ tests.cpp libgmock.a -o runTests player.o share.o management.o 

clean: ; rm $(TARGETS)

# The End
