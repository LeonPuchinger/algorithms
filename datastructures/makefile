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

queue:
	$(BUILDSTR) -c $(SRC)/queue.c -o $(BIN)/queue.o

example: stack queue
	$(BUILDSTR) $(SRC)/example.c $(BIN)/stack.o $(BIN)/queue.o -o $(BIN)/example
