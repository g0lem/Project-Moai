#include "../glheads.h"
#include "../shape.h"
#include "shaders/shaders.h"
#define GLFW_INCLUDE_ES2

static const GLuint WIDTH = 1920;
static const GLuint HEIGHT = 1080;

GLFWwindow* generateWindow() {
    GLFWwindow* window;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(WIDTH, HEIGHT, __FILE__, NULL, NULL);
    glfwMakeContextCurrent(window);

    printf("GL_VERSION  : %s\n", glGetString(GL_VERSION) );
    printf("GL_RENDERER : %s\n", glGetString(GL_RENDERER) );

    return window;
}


void renderGame(GLuint *shader_program, GLuint *vbo) {
    GLint pos;

    *shader_program = common_get_shader_program();
    pos = glGetAttribLocation(*shader_program, "position");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, WIDTH, HEIGHT);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    Shape *triangle = createTriangle();
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle->vertexList) * triangle->vertexSize, triangle->vertexList, GL_STATIC_DRAW);
    glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(pos);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void mainRenderLoop(GLFWwindow* window, GLuint shader_program) {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader_program);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        emscripten_sleep(100);
    }
}

void cleanupRenderer(GLuint vbo) {
    glDeleteBuffers(1, &vbo);
    glfwTerminate();
}

void gameLoop() {
    GLFWwindow* window = generateWindow();
    GLuint shader_program;
    GLuint vbo;

    renderGame(&shader_program, &vbo);

    mainRenderLoop(window, shader_program);

    cleanupRenderer(vbo);
}


