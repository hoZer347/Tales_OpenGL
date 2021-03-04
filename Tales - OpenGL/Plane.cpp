#include "Plane.h"

#include <iostream>

void Plane::load() {

	vertices = {
		0, 0, 0,  0, 0, 1,  1, 0, 1,  1, 0, 0
	};

	frame = {
		0, 0.001, 0,  0, 0.001, 1,  1, 0.001, 1,  1, 0.001, 0,  0, 0.001, 0
	};
}

void Plane::render() {
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices.data());
	glColor3f(v_color.x, v_color.y, v_color.z);
	glDrawArrays(GL_QUADS, 0, vertices.size()/3);

	glVertexPointer(3, GL_FLOAT, 0, frame.data());
	glColor3f(f_color.x, f_color.y, f_color.z);
	glDrawArrays(GL_LINE_LOOP, 0, frame.size()/3);

	glDisableClientState(GL_VERTEX_ARRAY);
}
