#pragma once

#include "Object.h"

#include "Cube.h"

class Cursor : public Object {
public:
	Cursor(glm::vec3 = { 0, 0, 0 });

	void operator+=(glm::vec3);
	void operator-=(glm::vec3);

	void operator=(glm::vec3);

	glm::vec3 pos;

	float speed = 1;
};

