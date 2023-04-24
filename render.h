
#include <GL/gl.h>
#include <GL/glut.h>


void drawSquare() {
    glColor3f(1.0, 0.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
}


void drawPoint(GLint xCoord, GLint yCoord) {
    glColor3f(1,0,1);
    glVertex2i(xCoord, yCoord);
}


void updateWorld() {
    int n = 7;
    int xArr[] = { 0, 10, 20, 30, 40, 50, 60};
    int yArr[] = { 0, 10, 20, 30, 40, 50, 60};

    for(int i = 0; i < n; i++) {
        drawPoint(xArr[i], yArr[i]);
    }
}

void drawWorld() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );
    glBegin(GL_POINTS);
        drawSquare();
    glEnd();
}

void renderFunction() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquare();
    // drawPoint(10,10);
    // drawWorld();
    glFlush();
}