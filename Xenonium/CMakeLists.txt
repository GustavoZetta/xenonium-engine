cmake_minimum_required(VERSION 3.21.0)
project(Xenonium VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GLFW automatically from GitHub
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
)

# Disable GLFW documentation and tests so it builds faster
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c" "src/*.hpp" "src/*.h")
add_library(Xenonium SHARED ${SOURCES})

set_target_properties(Xenonium PROPERTIES
    OUTPUT_NAME "Xenonium"
    PREFIX ""
)

target_include_directories(Xenonium PUBLIC dependencies)
target_include_directories(Xenonium PUBLIC src)

target_compile_definitions(Xenonium PRIVATE _XENONIUM_DLL)

target_link_libraries(Xenonium PUBLIC
    XEM
	glfw
	OpenGL::GL
)
