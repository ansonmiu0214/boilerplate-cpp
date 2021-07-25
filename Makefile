.PHONY: all build test clean

all: build test

build:
	cd build && cmake .. && make

test:
	cd build && ctest -V

clean:
	rm -rf bin
	cd build && make clean