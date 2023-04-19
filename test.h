#include <stdio.h>
#ifndef TEST_H
#define TEST_H

void printHelloWorld() {
    printf("Hello world! \n");
}

void penis() {
    int c;
    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
}

#endif // TEST_H