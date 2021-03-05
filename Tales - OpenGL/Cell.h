#pragma once

#include "Object.h"
#include "Plane.h"
#include "Unit.h"

class Cell : public Object {
public:
	Cell(glm::vec3);

	void render();

	Cell* U = NULL;
	Cell* R = NULL;
	Cell* D = NULL;
	Cell* L = NULL;

	glm::vec3 pos = { 0, 0, 0 };

	Unit* unit = NULL;
	Plane square;
};

