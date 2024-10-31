CC=g++
CFLAGS=-Wall -std=c++20

hc:
	@$(CC) main.cc -o main $(CFLAGS)

clean:
	@rm `find . -type f -executable`	