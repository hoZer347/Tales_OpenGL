#include "Cube.h"

void Cube::load() {
    vertices = {
        0, 0, 0,  0, 0, 1,  0, 1, 1,  0, 1, 0,
        1, 0, 0,  1, 0, 1,  1, 1, 1,  1, 1, 0,
        0, 0, 0,  0, 0, 1,  1, 0, 1,  1, 0, 0,
        0, 1, 0,  0, 1, 1,  1, 1, 1,  1, 1, 0,
        0, 0, 0,  0, 1, 0,  1, 1, 0,  1, 0, 0,
        0, 0, 1,  0, 1, 1,  1, 1, 1,  1, 0, 1
    };

    frame = {
        0, 0, 0,  0, 0, 1,  0, 1, 1,  0, 1, 0,  0, 0, 0,
        1, 0, 0,  1, 0, 1,  1, 1, 1,  1, 1, 0,  1, 0, 0,
        0, 0, 0,  0, 0, 1,  1, 0, 1,  1, 0, 0,  0, 0, 0,
        0, 1, 0,  0, 1, 1,  1, 1, 1,  1, 1, 0,  0, 1, 0,
        0, 0, 0,  0, 1, 0,  1, 1, 0,  1, 0, 0,  0, 0, 0,
        0, 0, 1,  0, 1, 1,  1, 1, 1,  1, 0, 1,  0, 0, 1,
    };
}

void Cube::render() {
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor4f(v_color.x, v_color.y, v_color.z, 1);
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glDrawArrays(GL_QUADS, 0, vertices.size()/3);

    glColor4f(f_color.x, f_color.y, f_color.z, 1);
    glVertexPointer(3, GL_FLOAT, 0, frame.data());
    glDrawArrays(GL_LINE_LOOP, 0, frame.size()/3);

    glDisableClientState(GL_VERTEX_ARRAY);
}
