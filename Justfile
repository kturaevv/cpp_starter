# init the project ./build cmake
init:
	mkdir -p ./build && cd ./build && cmake ..

# rebuild with cmake
build:
	cmake --build ./build

# run generated binary
run:
	./build/project_name

# rm generated binary
clean:
	rm ./build/project_name

# re-{clean,build,run}
re: clean build run
