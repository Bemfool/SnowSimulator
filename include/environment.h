#pragma once
#include "random.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Environment {
private:
	Environment() { }
	glm::vec3 m_Gravity = glm::vec3(0.0, -0.005, 0.0);
	glm::vec3 m_Wind = glm::vec3(0.0);
	float m_k = 10;
	float m_Interval = 0.8;

	float x_LeftBound  = -5.0;
	float x_RightBound =  5.0;
	float y_UpperBound = -5.0;
	float y_LowerBound =  5.0;
	float z_CloseBound =  5.0;
	float z_FarBound   = -5.0;

public:
	static Environment &getInstance() {
		static Environment m_pInstance;
		return m_pInstance;
	}
	bool outOfBound(glm::vec3 &pos);
	void setRndWind();

	void setGravity(const glm::vec3 &gravity) { m_Gravity = gravity; }
	void setWind(const glm::vec3 &wind) { m_Wind = wind; }
	void setK(const float density) { m_k = density; }
	void setInterval(const float interval) { m_Interval = interval; }
	void setXBound(float l, float r) { x_LeftBound = l; x_RightBound = r; }
	void setYBound(float u, float l) { y_UpperBound = u; y_LowerBound = l; }
	void setZBound(float c, float f) { z_CloseBound = c; z_FarBound = f; }
	const glm::vec3 getGravity() const { return m_Gravity; }
	const glm::vec3 getWind() const { return m_Wind; }
	const float getK() const { return m_k; }
	const float getInterval() const { return m_Interval; }
	const float getXLeftBound() { return x_LeftBound; }
	const float getXRightBound() { return x_RightBound; }
	const float getYUpperBound() { return y_UpperBound; }
	const float getYLowerBound() { return y_LowerBound; }
	const float getZCloseBound() { return z_CloseBound; }
	const float getZFarBound() { return z_FarBound; }
};