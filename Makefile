# Makefile for Selling Out.

# Compiler and Flags.
CC=clang++
CFLAGS=-g -std=c++11

TARGETS=share.o player.o management.o market_record.o starting_algorithm.o infraTests algTests
all: $(TARGETS)

share.o: share.cpp share.h ; $(CC) $(CFLAGS) -c share.cpp

player.o: player.cpp player.h ; $(CC) $(CFLAGS) -c player.cpp

management.o: management.h management.cpp ; $(CC) $(CFLAGS) -c management.cpp

market_record.o: market_record.h market_record.cpp ; $(CC) $(CFLAGS) -c market_record.cpp

starting_algorithm.o: starting_algorithm.h starting_algorithm.cpp ; $(CC) $(CFLAGS) -c starting_algorithm.cpp

infraTests: share.o player.o libgmock.a infraTests.cpp management.o ; $(CC) -isystem ${GTEST_DIR}/include -pthread -isystem ${GMOCK_DIR}/include infraTests.cpp libgmock.a -o infraTests player.o share.o management.o 

algTests: share.o player.o libgmock.a algTests.cpp management.o ; $(CC) -isystem ${GTEST_DIR}/include -pthread -isystem ${GMOCK_DIR}/include algTests.cpp libgmock.a -o algTests player.o share.o management.o market_record.o

clean: ; rm $(TARGETS)

# The End
