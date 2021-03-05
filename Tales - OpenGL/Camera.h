#pragma once

#include <glm.hpp>
#include <glew.h>
#include <glut.h>
#include <glfw3.h>
#include <gtc/matrix_transform.hpp>

#include "Cursor.h"

#include <iostream>

class Camera {
public:
	Camera();

	void operator+=(glm::vec3);
	void operator-=(glm::vec3);

	void move_towards(glm::vec3);
	void rotate(glm::vec3);
	void update();

	double distance = 0;
	int min_zoom = 0, max_zoom = 10;

	int v_s = 10; // Vertical rotation sensitivity
	int h_s = 10; // Horizontal rotation sensitivity

	glm::vec3 up =			{ 0, 1, 0 }; // Up Vector
	glm::vec3 right =		{ 0, 0, 1 }; // Right Vector
	glm::vec3 trgPos =		{ 0, 0, 0 }; // Position looked at by camera
	glm::vec3 camPos =		{ 0, 5, -5 }; // Camera's position
	glm::vec3 rotation =	{ 0, 0, 0 };
	glm::vec3 goal =		{ 0, 0, 0 };

	glm::mat3x3 roll;
	glm::mat3x3 yaw;
	glm::mat3x3 pitch;

	float speed = 0.09f;

	Cursor cursor;
};

