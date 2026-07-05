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
- [ ] My Own Math Utils Library - (XEM -> Xenonium Extensive Mathematics)
- [ ] 2D Rendering API with support for multiple Graphics APIs
- [ ] Entity Component System (ECS)
- [ ] Raytraced Audio System
- [ ] Event System

## How to use

See [(link should be here, its not)](https://github.com/GustavoZetta/xenonium-engine) for a detailed 
documentation on how to use the engine.

## Dependencies

The Xenonium Engine uses three main dependencies:
* [GLFW](https://www.glfw.org/)
* [GLAD](https://glad.dav1d.de/)
* [XEM (Xenonium Extensive Mathematics)](https://github.com/GustavoZetta/xenonium-engine/tree/main/XEM)

## Supported Plataforms

The engine is officially supported and tested on Windows and Linux.

## Prebuild Binaries

See [releases](https://github.com/GustavoZetta/xenonium-engine/releases) for latest compiled binaries.

## Compiling with CMake

To compile with [CMake](https://cmake.org/), make sure you got it installed <br>
All the dependencies are either header only or automatically downloaded.

GLFW needs X11 and Wayland support for compiling. In Windows, development headers are bundled in
with most IDEs, but Linux requires manual package installation.
### Ubuntu / Debian / Mint
`sudo apt install xorg-dev libwayland-dev libxkbcommon-dev`
### Fedora / RHEL / CentOS
`sudo dnf install wayland-devel libxkbcommon-devel libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel`
### Arch
`sudo pacman -S xorg-serverwayland libxkbcommon`

To compile, go through the following steps:
1. Clone this repository `git clone https://github.com/GustavoZetta/xenonium-engine`
2. Go to the repository directory `cd xenonium-engine`
3. Check the compiler paths from CMakePresets.json and make sure they are the right ones for your system
4. Choose a preset from the list `cmake --list-presets`
5. Configure the project `cmake --preset <configure-preset-name>`
6. Build the project `cmake --build --preset <build-preset-name>`
7. Or build an individual subdirectory `cmake --build --preset <build-preset-name> <subdirectory, eg. Xenonium>`