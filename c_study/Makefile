CC = gcc

CFLAGS = -Wall -Wextra -std=c11

SRC = problem7-3-3.c

TARGET = $(basename $(word 1, $(SRC)))

OBJ = $(SRC:.c=.o)

all: $(TARGET)

%.o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)