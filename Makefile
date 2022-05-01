CFLAGS = -Wall
SRC = src/main.c
all:
	gcc $(CFLAGS) $(SRC) -o bin
run: all
	./bin
clean:
	rm bin

%: clean
	gcc $(CFLAGS) $(SRC) -o bin
	./bin
