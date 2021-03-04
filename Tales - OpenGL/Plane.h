#pragma once

#include "Geometry.h"

class Plane : public Geometry {
public:
	Plane() { load(); }

	void load();
	void render();
};
