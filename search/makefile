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

bin_tree:
	$(BUILDSTR) -c $(SRC)/bin_search_tree.c -o $(BIN)/bin_search_tree.o

example: bin_tree
	$(BUILDSTR) $(SRC)/bin_search_tree.c $(SRC)/example.c -o $(BIN)/example
