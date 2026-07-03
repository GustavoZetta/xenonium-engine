# Xenonium Engine

This is my attempt at making an game engine from scratch using the following tutorials:
* [The Cherno Game Engine Series](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT)
* [Learn OpenGL](https://learnopengl.com/)
* [RasterTek OpenGL tutorials](https://www.rastertek.com/)
<br>
This project is my side hobby, so don't expect frequent updates.

## Objective

My objective with this engine is to gain a deep understanding behind how the math and graphics
works inside a game by doing it basically all by myself. <br>
The only two shortcuts that I'll be using is GLFW and GLAD. <br>
I'll be trying to do my best to keep a good and consistent code structure through the whole project.

## Features

This is the list of features that I will try to implement in the engine:

- [X] Reliable Window and Input System
- [ ] My Own Math Utils Library
- [ ] 2D Rendering API with support for multiple Graphics APIs
- [ ] Entity Component System (ECS)
- [ ] Raytraced Audio System
- [ ] Event System

## How to use

See [(link should here, its not)](https://github.com/GustavoZetta/xenonium-engine) for a detailed 
documentation on how to use the engine.

## Dependencies

The Xenonium Engine uses two main dependencies:
* [GLFW](https://www.glfw.org/)
* [GLAD](https://glad.dav1d.de/)

## Supported Plataforms

The engine is officially supported and tested on Windows and Linux.

## Prebuild Binaries

See [releases](https://github.com/GustavoZetta/xenonium-engine/releases) for latest compiled binaries.

## Compiling the Engine

The build system choosen for this project was [CMake](https://cmake.org/) <br>
All the dependencies are either header only or automatically downloaded.

To compile, go through the following steps:
1. Clone this repository using `git clone https://github.com/GustavoZetta/xenonium-engine`
2. Go to the repository directory `cd xenonium-engine`
3. Choose a preset to your plataform from the CMakePresets.json (Change the compiler paths if necessary)
4. Configure the project with `cmake --preset <configure-preset-name>`
5. Build the project with `cmake --build --preset <build-preset-name>`