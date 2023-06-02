

#ifndef SHAPE_H
#define SHAPE_H
#include "types.h"
#include "glheads.h"

struct Shape{
    float *vertexList;
    int vertexSize;
};

typedef struct Shape Shape;


struct Shape *createTriangle() {
    Shape *triangle = malloc(sizeof(Shape));

    triangle->vertexSize = 10;

    triangle->vertexList = malloc(sizeof(float) * triangle->vertexSize);

    triangle->vertexList[0] = 0.0f;
    triangle->vertexList[1] = 0.5f;
    triangle->vertexList[2] = 0.0f;

    triangle->vertexList[3] = 0.5f;
    triangle->vertexList[4] = -0.5f;
    triangle->vertexList[5] = 0.0f;

    triangle->vertexList[6] = -0.5f;
    triangle->vertexList[7] = -0.5f;
    triangle->vertexList[8] = 0.0f;

    return triangle;
}


#endif // SHAPE_H

