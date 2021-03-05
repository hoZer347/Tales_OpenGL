#pragma once

#include "Object.h"
#include "Sprite.h"

#include <String>

class Unit : public Object {
public:
	Unit(std::string);

	std::string name;
};

