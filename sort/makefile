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
	$(BUILDSTR) -c $(SRC)/insertion_sort.c -o $(BIN)/ins_srt.o

bub_srt:
	$(BUILDSTR) -c $(SRC)/bubble_sort.c -o $(BIN)/bub_srt.o

sel_srt:
	$(BUILDSTR) -c $(SRC)/selection_sort.c -o $(BIN)/sel_srt.o

qck_srt:
	$(BUILDSTR) -c $(SRC)/quick_sort.c -o $(BIN)/qck_srt.o

mrg_srt:
	$(BUILDSTR) -c $(SRC)/merge_sort.c -o $(BIN)/mrg_srt.o

heap_srt:
	$(BUILDSTR) -c $(SRC)/heap_sort.c -o $(BIN)/heap_srt.o

cnt_srt:
	$(BUILDSTR) -c $(SRC)/count_sort.c -o $(BIN)/cnt_srt.o

map_srt:
	$(BUILDSTR) -c $(SRC)/map_sort.c -o $(BIN)/map_srt.o

example: ins_srt bub_srt sel_srt qck_srt mrg_srt heap_srt cnt_srt map_srt
	$(BUILDSTR) $(SRC)/example.c $(BIN)/ins_srt.o $(BIN)/bub_srt.o $(BIN)/sel_srt.o \
		$(BIN)/qck_srt.o $(BIN)/mrg_srt.o $(BIN)/heap_srt.o $(BIN)/cnt_srt.o $(BIN)/map_srt.o -o $(BIN)/example
