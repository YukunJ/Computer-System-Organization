BUILD  := build
STATIC := static

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	STATIC := static-mac
endif

SOURCES := src/part1.c

SOBJS :=	$(STATIC)/part1_harness.o 

CC     := gcc
CFLAGS := -Werror -std=gnu99 -g

OBJS :=	$(BUILD)/part1 $(BUILD)/mywc


all: $(OBJS)
	@:

real_all: $(OBJS)

$(BUILD)/mywc: src/mywc.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -g src/mywc.c -o $(BUILD)/mywc


$(STATIC)/part%_harness.o: src/part%_harness.c
	$(CC) $(CFLAGS) -g -c src/part$*_harness.c -o $(STATIC)/part$*_harness.o

$(BUILD)/part%: src/part%.c $(SOBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -g -c src/part$*.c -o $(BUILD)/part$*.o
	$(CC) $(CFLAGS) $(STATIC)/part$*_harness.o $(BUILD)/part$*.o -lm -o $(BUILD)/part$*

clean-logs: always
	rm -f *.out

clean: always clean-logs
	rm -rf $(BUILD)


.PHONY: all always
