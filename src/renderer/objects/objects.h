

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







#endif // OBJECTS_H

