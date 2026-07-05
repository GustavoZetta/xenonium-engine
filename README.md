# Xenonium Engine

An simple game engine made (almost) from scratch. <br>
Some of the code of this engine was inspired by [The Cherno Game Engine Series](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT), [Learn OpenGL](https://learnopengl.com/), [RasterTek tutorials](https://www.rastertek.com/) and [Game Engine Architecture by Jason Gregory](https://www.gameenginebook.com/).<br>
<br>
This project is my side hobby, so don't expect frequent updates.

## Objective

The objective of this engine is to be simplistic and easy to understand, but also to do most things
from scratch. The only two shortcuts that are being used are GLFW and GLAD.

## Features

This is the list of features that I will try to implement in the engine:

- [X] Reliable Window and Input System
- [ ] My Own Math Utils Library (XEM -> Xenonium Extensive Mathematics)
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
* [XEM](https://github.com/GustavoZetta/xenonium-engine/tree/main/XEM)

## Supported Plataforms

The engine is officially supported and tested on Windows and Linux.

## Prebuild Binaries

See [releases](https://github.com/GustavoZetta/xenonium-engine/releases) for latest compiled binaries.

## Compiling with CMake

To compile with [CMake](https://cmake.org/), make sure you've got it installed. <br>
All the dependencies on this project are either header only or automatically downloaded. <br>
<br>
GLFW needs X11 and Wayland support for compiling. In Windows, development headers are bundled in
with most IDEs, but Linux requires manual package installation.
### Packages required
Ubuntu / Debian / Mint <br>
`sudo apt install xorg-dev libwayland-dev libxkbcommon-dev` <br>
<br>
Fedora / RHEL / CentOS <br>
`sudo dnf install wayland-devel libxkbcommon-devel libXcursor-devel` <br>
`sudo dnf install libXi-devel libXinerama-devel libXrandr-devel` <br>
<br>
Arch <br>
`sudo pacman -S xorg-serverwayland libxkbcommon` <br>

### Compilation
To compile, go through the following steps:
1. Clone this repository `git clone https://github.com/GustavoZetta/xenonium-engine`
2. Go to the repository directory `cd xenonium-engine`
3. Check the compiler paths from CMakePresets.json and make sure they are the right ones for your system
4. Choose a preset from the list `cmake --list-presets`
5. Configure the project `cmake --preset <configure-preset-name>`
6. Build the project `cmake --build --preset <build-preset-name>`
7. Or build an individual subdirectory `cmake --build --preset <build-preset-name> <subdirectory, eg. Xenonium>`