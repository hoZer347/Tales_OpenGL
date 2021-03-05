#include "Sprite.h"

#include <iostream>

Sprite::Sprite(std::string f) {
	f += ".png";
	file_name = f.c_str();

	load();
}

void Sprite::operator+=(glm::vec3 V) {
	auto v = vertices.begin();

	while (v != vertices.end()) {
		*v += V.x;
		v++;
		*v += V.y;
		v++;
		*v += V.z;
		v++;
	}

	//v = frame.begin();

	//while (v != frame.end()) {
	//	*v += V.x;
	//	v++;
	//	*v += V.y;
	//	v++;
	//	*v += V.z;
	//	v++;
	//}
}
void Sprite::operator-=(glm::vec3 V) {
	auto v = vertices.begin();

	while (v != vertices.end()) {
		*v -= V.x;
		v++;
		*v -= V.y;
		v++;
		*v -= V.z;
		v++;
	}

	//v = frame.begin();

	//while (v != frame.end()) {
	//	*v -= V.x;
	//	v++;
	//	*v -= V.y;
	//	v++;
	//	*v -= V.z;
	//	v++;
	//}
}

void Sprite::load() {
	vertices = {
		0, 1.2, 1.5,  0, 0, 1.5,  1, 0, 1.5,  1, 1.2, 1.5
	};

	frame = {
		0, 0,  0, 1.0/144,  1.0/12, 1.0/144,  1.0/12, 0
	};

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	int width, height;
	unsigned char* image = SOIL_load_image(file_name, &width, &height, 0, SOIL_LOAD_AUTO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

// Hacky, but works
void Sprite::render() {
	glBindTexture(GL_TEXTURE_2D, texture);

	glColor4f(1, 1, 1, 1);

	glPushMatrix();

	glBegin(GL_QUADS);
	glTexCoord2f(frame[0], frame[1]); glVertex3f(vertices[0], vertices[1], vertices[2]);
	glTexCoord2f(frame[2], frame[3]); glVertex3f(vertices[3], vertices[4], vertices[5]);
	glTexCoord2f(frame[4], frame[5]); glVertex3f(vertices[6], vertices[7], vertices[8]);
	glTexCoord2f(frame[6], frame[7]); glVertex3f(vertices[9], vertices[10], vertices[11]);
	glEnd();

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
}
