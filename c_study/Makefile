CC = gcc

CFLAGS = -Wall -Wextra -std=c11

SRC = problem_5-1-5.c

TARGET = $(basename $(word 1, $(SRC)))

OBJ = $(SRC:.c=.o)

all: $(TARGET)

%.o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

test: $(TARGET)
	./$(TARGET)
	$(MAKE) clean

clean:
	rm -f $(TARGET) $(OBJ)