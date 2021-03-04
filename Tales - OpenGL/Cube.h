#pragma once

#include "Geometry.h"

class Cube : public Geometry {
public:
	Cube() { load(); }

	void load();
	void render();
};

