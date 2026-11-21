CC = clang
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -I include
TARGET = expense_tracker
SRC = src/main.c src/expense.c src/menu.c
HEADERS = include/expense.h include/menu.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean