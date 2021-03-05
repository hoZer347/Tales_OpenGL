#pragma once

#include <glm.hpp>
#include <glew.h>
#include <glut.h>
#include <glfw3.h>

#include <vector>

#include "Geometry.h"

class Object {
public:
	void operator+=(glm::vec3);
	void operator-=(glm::vec3);

	void render();

	std::vector<Geometry*> geometry;
};
