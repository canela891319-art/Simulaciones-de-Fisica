CC = gcc

CFLAGS = -Wall -Wextra -std=c99 -I../comun/include

LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/main.c ../comun/src/physics.c ../comun/src/rendering.c ../comun/src/interaction.c

OBJS = $(SRCS:.c=.o)

TARGET = bin/simulador

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
