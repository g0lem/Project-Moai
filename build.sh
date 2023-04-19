#!/bin/bash

# gcc main.c && ./a.out

#OpenGL
clear
gcc gl_test.c -lglut -lGL -lGLEW -lGLU && ./a.out