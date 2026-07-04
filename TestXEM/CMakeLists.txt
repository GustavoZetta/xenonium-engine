cmake_minimum_required(VERSION 3.21.0)
project(TestXEM VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c" "src/*.hpp" "src/*.h")
add_executable(TestXEM ${SOURCES})

target_include_directories(TestXEM PRIVATE src)

target_link_libraries(TestXEM PRIVATE Xenonium)
