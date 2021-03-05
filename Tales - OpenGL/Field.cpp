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
			
			if (i > 5 && j > 5) {
				temp_cells[j]->square += glm::vec3(0, 1, 0);
				temp_cells[j]->pos += glm::vec3(0, 1, 0);
			}
			
			if (i > 10 && j > 10) {
				temp_cells[j]->square += glm::vec3(0, 1, 0);
				temp_cells[j]->pos += glm::vec3(0, 1, 0);
			}

			if (i > 15 && j > 15) {
				temp_cells[j]->square += glm::vec3(0, 1, 0);
				temp_cells[j]->pos += glm::vec3(0, 1, 0);
			}

			if (i > 20 && j > 20) {
				temp_cells[j]->square += glm::vec3(5, 1, 5);
				temp_cells[j]->pos += glm::vec3(5, 1, 5);
			}

			if (i > 25 && j > 25) {
				temp_cells[j]->square += glm::vec3(0, 1, 0);
				temp_cells[j]->pos += glm::vec3(0, 1, 0);
			}
		}

		cells.push_back(temp_cells);
	}

	hovered = cells[0][0];
}

Field::~Field() {

}

void Field::add_unit(Unit* u, int x, int y) {
	cells[x][y]->unit = u;
	*u += cells[x][y]->pos;
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
