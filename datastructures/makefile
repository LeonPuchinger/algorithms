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

stack:
	$(BUILDSTR) -c $(SRC)/stack.c -o $(BIN)/stack.o

example: stack
	$(BUILDSTR) $(SRC)/example.c $(BIN)/stack.o -o $(BIN)/example
