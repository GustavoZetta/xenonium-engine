cmake_minimum_required(VERSION 3.21.0)
project(XEM VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c" "src/*.hpp" "src/*.h")
add_library(XEM SHARED ${SOURCES})

set_target_properties(XEM PROPERTIES
    OUTPUT_NAME "XEM"
    PREFIX ""
)

target_include_directories(XEM PUBLIC include)
target_include_directories(XEM PUBLIC src)
