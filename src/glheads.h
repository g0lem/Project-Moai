#ifndef GL_HEADS_H
#define GL_HEADS_H

#include <GLFW/glfw3.h>


#endif // GL_HEADS_H

#ifdef EMSCRIPTEN
    #include <emscripten.h>
    #include <emscripten/html5.h>   
    #include <GL/gl.h>
#else
    #include "emscripten.h"
#endif