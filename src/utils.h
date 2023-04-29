#include <stdio.h>
char* fileToString(char* file_path) {
    char* buffer = NULL;
    FILE* file = fopen(file_path, "rb");

    if(!file) {
        printf("\n could not open file %s \n", file_path);
        return NULL;
    }

    fseek(file, 0L, SEEK_END);
    long length = ftell(file);
    rewind(file);
    buffer = malloc(length*sizeof(char) + 2);
    if (buffer) {
        fread(buffer, 1, length, file);
        buffer[length+1] = '\0';
    }
    fclose(file);

    printf("\n loaded shader from: %s \n", file_path);

    return buffer;
}
