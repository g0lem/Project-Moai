

struct VertexList {

    int size;
    float vertex;
    struct VertexList* next;
    struct VertexList* back;
};

typedef struct VertexList VertexList;

VertexList* createVertexList(float vertex){

    VertexList* myVertexList = malloc(sizeof(VertexList));

    myVertexList->size = 1;
    myVertexList->vertex = vertex;
    myVertexList->next = NULL;
    myVertexList->back = NULL;

    return myVertexList;
}

VertexList* getLastElement(VertexList* myVertexList) {
    VertexList* itterator = myVertexList;
    while(itterator->next != NULL) {
        itterator = itterator->next;
    }
    return itterator;
}


VertexList* getFirstElement(VertexList* myVertexList) {
    VertexList* itterator = myVertexList;
    while(itterator->back != NULL) {
        itterator = itterator->back;
    }
    return itterator;
}


void pushElement(VertexList* myVertexList, VertexList* vertexElement) {

    myVertexList->size++;

    VertexList* item = vertexElement;

    VertexList* lastElement = getLastElement(myVertexList);

    lastElement->next = item;
    item->back = lastElement;
}

void pushVertex(VertexList* myVertexList, float vertex) {

    VertexList* item = createVertexList(vertex);

    pushElement(myVertexList, item);
}

VertexList* deleteVertex(VertexList* item) {
    VertexList *itemBefore = item->back;
    VertexList *itemAfter = item->next;

    if(!itemBefore) {
        itemAfter->back = itemBefore;
        return itemAfter;
    }

    itemBefore->next = itemAfter;
    itemAfter->back = itemBefore;

    free(item);

    VertexList *myVertextList = getFirstElement(itemBefore);
    myVertextList->size--;

    return myVertextList;
}

float *vertextListToArray(VertexList* item) {
    VertexList* myVertexList = getFirstElement(item);
    int size = myVertexList->size;
    float *array = malloc(sizeof(float) * (size + 1));

    VertexList *itterator = myVertexList;

    for(int i=0; i<size && itterator->next != NULL; i++) {
        array[i] = itterator->vertex;
        itterator = itterator->next;
    }
    
    return array;
}
