#ifndef GL_HEADS_H
#define GL_HEADS_H

#include <GLFW/glfw3.h>


#ifdef EMSCRIPTEN
    #include <emscripten.h>
    #include <emscripten/html5.h>   
    #include <GL/gl.h>
#else
    #include "emscripten.h"
#endif


#endif // GL_HEADS_H