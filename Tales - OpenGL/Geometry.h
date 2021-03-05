#pragma once

#include <glm.hpp>
#include <glew.h>
#include <glut.h>
#include <glfw3.h>

#include <vector>

class Geometry {
public:
	Geometry();
	~Geometry();

	void operator+=(glm::vec3);
	void operator-=(glm::vec3);
	void operator*=(int);
	void operator/=(int);

	virtual void load()=0;
	virtual void render()=0;

	int scale = 1;

	std::vector<GLfloat> vertices;
	std::vector<GLfloat> frame;

	glm::vec3 pos = { 0, 0, 0 };

	glm::vec3 v_color = { 1, 1, 1 };
	glm::vec3 f_color = { 1, 0, 0 };

	GLuint* vertexBuffer;
};

