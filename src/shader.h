#include "glheads.h"

const char *vertex_shader =
    "#version 300 es\n  in vec3 vp; void main() {   gl_Position = vec4(vp, 1.0); }";

const char *fragment_shader =
    "#version 300 es\n precision mediump float; out vec4 frag_colour; void main() {   frag_colour = vec4(0.5f, 0.0f, 0.5f, 1.0f); }";

GLuint createShader() {
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);

    return shader_programme;
}