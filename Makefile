CC=gcc
CFLAGS= -Wall -g -pedatic -std=c11
EXEC=calc

run:



clean:
		rm -rf ./build

build:
		mkdir -p build

cleanall:
		rm -rf ./build
