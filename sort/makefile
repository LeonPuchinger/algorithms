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

insertion_sort:
	$(BUILDSTR) -c $(SRC)/insertion_sort.c -o $(BIN)/insertion_sort

bubble_sort:
	$(BUILDSTR) -c $(SRC)/bubble_sort.c -o $(BIN)/bubble_sort

example: insertion_sort bubble_sort
	$(BUILDSTR) $(SRC)/example.c $(BIN)/insertion_sort $(BIN)/bubble_sort -o $(BIN)/example
