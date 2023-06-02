#!/bin/bash

# gcc main.c && ./a.out
source ./emsdk/emsdk_env.sh
#OpenGL
clear
emcc ./src/main.c -s MIN_WEBGL_VERSION=2 -s ASYNCIFY -s USE_GLFW=3 -o server/public/main.html --embed-file src/assets
gcc src/main.c -lglfw -lglut -lGLESv2 -lGLEW -lGLU && ./a.out
