#ifndef GL_HEADS_H
#define GL_HEADS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#endif // GL_HEADS_H

#ifdef EMSCRIPTEN
    #include <emscripten.h>
    #include <emscripten/html5.h>   
    #include <GL/gl.h>
    #include <GLES3/gl3.h>
#else
    #include "emscripten.h"
    #include <GL/gl.h>
#endif