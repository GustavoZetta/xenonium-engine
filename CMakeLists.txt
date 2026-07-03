cmake_minimum_required(VERSION 3.21.0)
project(XenoniumTests VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Build")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Xenonium)
add_subdirectory(TestGame)

message(STATUS "-------------------------------------------------")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Version: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Version: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "-------------------------------------------------")