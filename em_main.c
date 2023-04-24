#define __EMSCRIPTEN__ 1

#include <stdio.h>
#include "test.h"

#include "gl_test.h"

int main (int argc, char** argv) {
    printHelloWorld();
    printf("hello world2 \n");
    return 0;
}
