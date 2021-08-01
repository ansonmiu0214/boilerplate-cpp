.PHONY: all build test valgrind clean

all: build test

build:
	cd build;			\
	cmake .. && make;	\
	cd ..;

test:
	cd build;	\
	ctest -V;	\
	cd ..;

valgrind:
	./scripts/run_valgrind_on_tests.sh build/bin

clean:
	cd build;	\
	make clean;	\
	cd ..;