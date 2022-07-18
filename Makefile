TARGET=main
CC=gcc

SRCS  = $(shell find ./src     -type f -name "*.c")
HEADS = $(shell find ./include -type f -name "*.h")
OBJS = $(SRCS:.c=.o)

INCLUDES = -I./include
CFLAGS = -g -Wall $(INCLUDES)


debug: CFLAGS += -ggdb
all: $(TARGET)

$(TARGET): $(OBJS) $(HEADS)
	$(CC) -o $@ $(OBJS)

run: all
	@./$(TARGET)

.PHONY: depend clean test
depend:
	$(CC) $(INCLUDES) -MM $(SRCS)

clean:
	$(RM) $(OBJS) $(TARGET)

test:
	@./$(TARGET) data/csvs/first.csv data/csvs/second.csv
