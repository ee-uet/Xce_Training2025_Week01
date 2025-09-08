CC = gcc
CFLAGS = -Wall -g

TARGET = E5_1

SRC = E5_1_main.c E5_1_function.c

all: run

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./E5_1

clean:
	rm -f $(TARGET)
