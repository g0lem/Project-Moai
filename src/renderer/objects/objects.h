

#ifndef OBJECTS_H
#define OBJECTS_H
#include "../../types.h"
#include "../../glheads.h"
#include "../../utils/utils.h"

struct Object{
    VertexList *geometricVertices;
    VertexList *textureCoords;
    VertexList *vertexNormals;
    VertexList *spaceVertices;
};

typedef struct Object Object;







#endif // OBJECTS_H

