#include "Cursor.h"

Cursor::Cursor(glm::vec3 v) {
	pos = v;

	Cube* cube = new Cube();

	*cube /= 2;
	*cube -= glm::vec3(0.25, 0, 0.25);

	geometry.push_back(cube);
}

void Cursor::operator+=(glm::vec3 v) {
	pos += v;
	*geometry[0] += v;
}
void Cursor::operator-=(glm::vec3 v) {
	pos -= v*speed;
	*geometry[0] -= v*speed;
}
void Cursor::operator=(glm::vec3 v) {
	*geometry[0] -= pos - v;
	pos = v;
}
