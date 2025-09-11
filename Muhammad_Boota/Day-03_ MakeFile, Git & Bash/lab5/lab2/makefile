FILES=*.c
TARGET=main
all:c run clean
c:$(FILES)
	@gcc $(FILES) -o  $(TARGET) -lm
run:c
	@./$(TARGET)
debug:
	gcc -g $(FILES) -o $(TARGET) -lm
clean:
	@rm -f $(TARGET)
 
