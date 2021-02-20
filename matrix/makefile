CC := cc
DEBUG ?= 0
OPTIMIZE ?= 0
SRC := src
BIN := bin
BUILDSTR = $(CC) $(CCFLAGS)

ifeq ($(DEBUG), 1)
CCFLAGS += -g
endif

ifeq ($(OPTIMIZE), 1)
CCFLAGS += -O3
endif

all: setup build

setup:
	mkdir -p $(BIN)

build: example

naive:
	$(BUILDSTR) -c $(SRC)/matrix.c -o $(BIN)/matrix.o

strassen:
	$(BUILDSTR) -c $(SRC)/strassen.c -o $(BIN)/strassen.o

example: naive strassen
	$(BUILDSTR) -lm $(SRC)/example.c $(BIN)/matrix.o $(BIN)/strassen.o -o $(BIN)/example
