#include "Field.h"

#include <iostream>

Field::Field(int x, int y) {
	std::vector<Cell*> temp_cells;

	x_size = x;
	y_size = y;

	for (int i = 0; i < x; i++) {
		temp_cells.clear();

		for (int j = 0; j < x; j++) {
			temp_cells.push_back(new Cell(glm::vec3(i, 0, j)));
		}

		cells.push_back(temp_cells);
	}

	hovered = cells[0][0];

	cells[2][2]->square += glm::vec3(0, 5, 0);
	cells[2][2]->pos += glm::vec3(0, 5, 0);

	cells[0][2]->square += glm::vec3(0, -5, 0);
	cells[0][2]->pos += glm::vec3(0, -5, 0);
}

Field::~Field() {

}

void Field::render() {
	for (auto& C : cells)
		for (auto& c : C)
			c->render();
}

glm::vec3 Field::at(glm::vec3 v) {
	glm::vec3 pos;
	if (v.x > 0 && v.x < x_size && v.z > 0 && v.z < y_size) {
		pos = cells[(int)v.x][(int)v.z]->pos;
		hovered->square.v_color = { 1, 1, 1 };
		hovered = cells[pos.x][pos.z];
		hovered->square.v_color = { 0, 0, 1 };
		pos += 0.5;
		return pos;
	}

	pos = hovered->pos;
	pos += 0.5;

	return pos;
}
