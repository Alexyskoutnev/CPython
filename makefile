CC = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

TARGET = bin/main
SRCS = scripts/main.c src/hello.c src/print.c src/parser.c src/keywords.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

clean:
	rm -f $
