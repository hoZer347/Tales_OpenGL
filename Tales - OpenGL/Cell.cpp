#include "Cell.h"

#include <iostream>

Cell::Cell(glm::vec3 v) {
	pos.x = v.x;
	pos.y = v.y;
	pos.z = v.z;

	square.load();

	square += v;
}

void Cell::render() {
	square.render();
}
