# Xenonium Engine

This is my attempt at making an game engine from scratch using tutorials from 
[The Cherno Game Engine Series](https://www.youtube.com/watch?v=sULV3aB2qeU), 
[Learn OpenGL](https://learnopengl.com/) and 
[RasterTek OpenGL tutorials](https://www.rastertek.com/) <br>
This is also my side hobby, so don't expect anything really big or complex.

## Features

This is the list of features that I will try to implement in the engine:

- [X] Reliable Window and Input System
- [ ] 2D Rendering API with support for multiple Graphics APIs
- [ ] Entity Component System (ECS)
- [ ] Raytraced Audio System
- [ ] Event System

## How to use

(WIP)

## Dependencies

The Xenonium Engine uses three main dependencies:
* [GLFW](https://www.glfw.org/)
* [GLAD](https://glad.dav1d.de/)
* [GLM](https://glm.g-truc.net/0.9.9/index.html)

## Supported Plataforms

The engine is officially supported and tested only on Windows, but it should compile just fine on other plataforms such as Linux and MacOS

## Prebuild Binaries

See the [releases page](https://github.com/GustavoZetta/xenonium-engine/releases) for latest compiled binaries.

## Compiling the Engine

The build system choosen for this project was [CMake](https://cmake.org/) <br>
All the dependencies are either header only or automatically downloaded.

To compile, go through the following steps:
1. Clone this repository using `git clone https://github.com/GustavoZetta/xenonium-engine`
2. Go to the repository directory `cd xenonium-engine`
3. Run CMake Reconfigure `cmake .`
4. Build with CMake `cmake --build .`