#include "Object.h"

void Object::operator+=(glm::vec3 v) {
	for (auto& g : geometry)
		*g += v;
}
void Object::operator-=(glm::vec3 v) {
	for (auto& g : geometry)
		*g -= v;
}

void Object::render() {
	for (auto& g : geometry)
		g->render();
}
