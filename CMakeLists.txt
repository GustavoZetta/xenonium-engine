cmake_minimum_required(VERSION 4.0.0)
project(VenusTest VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Build")

add_custom_target(ForceReconfigure ALL)

add_custom_command(
	TARGET ForceReconfigure
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E rm -f "${CMAKE_BINARY_DIR}/CMakeFiles/generate.stamp"
)

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