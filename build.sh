#!/bin/bash

# gcc main.c && ./a.out

#OpenGL
clear
gcc src/main.c -lglfw -lglut -lGL -lGLEW -lGLU && ./a.out