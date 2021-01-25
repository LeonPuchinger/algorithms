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

ins_srt:
	$(BUILDSTR) -c $(SRC)/insertion_sort.c -o $(BIN)/ins_srt

bub_srt:
	$(BUILDSTR) -c $(SRC)/bubble_sort.c -o $(BIN)/bub_srt

sel_srt:
	$(BUILDSTR) -c $(SRC)/selection_sort.c -o $(BIN)/sel_srt

qck_srt:
	$(BUILDSTR) -c $(SRC)/quick_sort.c -o $(BIN)/qck_srt

mrg_sort:
	$(BUILDSTR) -c $(SRC)/merge_sort.c -o $(BIN)/mrg_sort

example: ins_srt bub_srt sel_srt qck_srt mrg_sort
	$(BUILDSTR) $(SRC)/example.c $(BIN)/ins_srt $(BIN)/bub_srt $(BIN)/sel_srt $(BIN)/qck_srt $(BIN)/mrg_sort -o $(BIN)/example
