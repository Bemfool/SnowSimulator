#include "environment.h"


void Environment::setRndWind() {
	m_Wind = glm::vec3(normal_random(0.0, 0.001), 0.0, normal_random(0.0, 0.001));
}


bool Environment::outOfBound(glm::vec3 &pos) {
	return pos.y < y_LowerBound | pos.y > y_UpperBound |
		   pos.x < x_LeftBound  | pos.x > x_RightBound |
		   pos.z < z_FarBound   | pos.z > z_CloseBound;
}