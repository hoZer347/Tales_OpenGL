#pragma once

#include "Cell.h"

class Field {
public:
	Field(int=32, int=32);
	~Field();

	glm::vec3 at(glm::vec3);

	void render();

	int x_size, y_size;

	Cell* hovered = NULL;

	std::vector<std::vector<Cell*>> cells;
};

