# init the project ./build cmake
init:
	cmake --preset=default

# rebuild with cmake
build:
	cmake --build build

# run generated binary
run:
	./build/cpp_starter

test:
	./build/tests

# rm generated binary
clean:
	rm ./build/cpp_starter

# re-{clean,build,run}
re: clean build run test
