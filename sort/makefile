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

build: test

insertion_sort:
	$(BUILDSTR) -c $(SRC)/insertion_sort.c -o $(BIN)/insertion_sort

test: insertion_sort
	$(BUILDSTR) $(SRC)/test.c $(BIN)/insertion_sort -o $(BIN)/test
