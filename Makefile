CFLAGS = -Wall
SRC = src/main.c
all:
	gcc $(CFLAGS) $(SRC) -o bin
run: all
	./bin
clean:
	rm bin

%.o: %.c
	gcc $(CFLAGS) %.c
