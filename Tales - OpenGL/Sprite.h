#pragma once

#include <SOIL.h>

#include "Geometry.h"

#include <map>

#include <String>
#include <functional>

class Sprite : public Geometry {
public:
	Sprite(std::string);
	
	void operator+=(glm::vec3);
	void operator-=(glm::vec3);

	void load();
	void render();

	const char* file_name = "";

	GLuint texture;

	std::map<std::string, GLuint*>* textures;
};

