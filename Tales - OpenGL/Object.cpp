#include "Object.h"

void Object::render() {
	for (auto& g : geometry)
		g->render();
}