CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%: %.o
	$(CC) $(CFLAGS) -o $@ $^

test: 
	@if [ "$(FILE)" = "" ]; then \
		echo "Usage: make test FILE=filename.c"; \
	else \
		$(CC) $(CFLAGS) -o $(basename $(FILE)) $(FILE) && ./$(basename $(FILE)) && $(MAKE) clean FILE=$(FILE); \
	fi

clean:
	@if [ -z "$(FILE)" ]; then \
		rm -f *.o; \
	else \
		rm -f $(basename $(FILE)) $(basename $(FILE)).o; \
	fi

%:
	@: