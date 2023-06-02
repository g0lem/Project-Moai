

#ifndef OBJECTS_H
#define OBJECTS_H
#include "../../types.h"
#include "../../glheads.h"
#include "../../utils/utils.h"

struct Object3D{
    VertexList *geometricVertices;
    VertexList *textureCoords;
    VertexList *vertexNormals;
    VertexList *spaceVertices;
};

typedef struct Object3D Object3D;

//Load file to a string
//use strtok to get each line
//look for the first letters on each line and create a switch case based on the vertex type
//use atof() to convert char to float





#endif // OBJECTS_H

