#include "Camera.h"

Camera::Camera() {

}

void Camera::move_towards(glm::vec3 v) {
	if (abs(trgPos.x - v.x) < speed) { camPos.x -= trgPos.x - v.x; trgPos.x = v.x; }
	else if (v.x < trgPos.x) { trgPos.x -= speed; camPos.x -= speed; }
	else if (v.x > trgPos.x) { trgPos.x += speed; camPos.x += speed; }

	if (abs(trgPos.y - v.y) < speed) { camPos.y -= trgPos.y - v.y; trgPos.y = v.y; }
	else if (v.y < trgPos.y) { trgPos.y -= speed; camPos.y -= speed; }
	else if (v.y > trgPos.y) { trgPos.y += speed; camPos.y += speed; }

	if (abs(trgPos.z - v.z) < speed) { camPos.z -= trgPos.z - v.z; trgPos.z = v.z; }
	else if (v.z < trgPos.z) { trgPos.z -= speed; camPos.z -= speed; }
	else if (v.z > trgPos.z) { trgPos.z += speed; camPos.z += speed; }
}

void Camera::rotate(glm::vec3 v) {
	rotation.y += v.y;

	yaw = {
		cos(rotation.y),	0,		-sin(rotation.y),
		0,			1,		0,
		sin(rotation.y),	0,		cos(rotation.y)
	};
}

void Camera::update() {
	move_towards(goal);

	glm::vec3 view = glm::vec3(
		camPos.x,
		camPos.y+distance,
		camPos.z-distance);

	view -= trgPos;
	view = yaw * view;
	view += trgPos;

	gluLookAt(
		view.x, view.y, view.z,
		trgPos.x, trgPos.y, trgPos.z,
		0, 1, 0);

	cursor.render();
}

void Camera::operator+=(glm::vec3 v) {
	v = yaw * v;

	cursor += v;
}
void Camera::operator-=(glm::vec3 v) {
	v = yaw * v;

	cursor -= v;
}
