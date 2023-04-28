#!/bin/bash

# gcc main.c && ./a.out

#OpenGL
clear
emcc ./src/main.c -s MIN_WEBGL_VERSION=2 -s FORCE_FILESYSTEM -s ASYNCIFY -s USE_GLFW=3 -o server/public/main.html
gcc src/main.c -lglfw -lglut -lGLESv2 -lGLEW -lGLU && ./a.out