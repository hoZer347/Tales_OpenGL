#pragma once

#include <glm.hpp>
#include <glew.h>
#include <glut.h>
#include <glfw3.h>

#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include <functional>

#include <list>
#include <vector>

#include "Object.h"
#include "Field.h"
#include "Player.h"
#include "Camera.h"
#include "Cursor.h"

#include "math.h"

class Battle {
public:
	Battle();
	~Battle();

	void init();

	// Input processing
	std::function<void()> inputs = [&]() { return; };
	void input_default();

	// Called every time a input is detected
	static void DefaultKeyCall(GLFWwindow*, int, int, int, int);
	static void DefaultScrollCall(GLFWwindow*, double, double);

private:
	GLFWwindow* window;

	Player player;
	Camera cam;

	Field* field = new Field(16, 16);

	double mx = 0, my = 0;

	std::vector<Object*> objects;
};

