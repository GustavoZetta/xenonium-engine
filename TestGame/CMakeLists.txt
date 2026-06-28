cmake_minimum_required(VERSION 4.0.0)
project(TestGame VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "src/*.hpp" "src/*.h")
add_executable(TestGame ${SOURCES})

target_include_directories(TestGame PRIVATE src)

target_link_libraries(TestGame PRIVATE
	Xenonium
)
