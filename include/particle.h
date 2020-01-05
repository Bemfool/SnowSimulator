#pragma once
#include "constant.h"
#include "environment.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


/* Class: Particle
 ****************************************************************
 * Used for every particle in a particle system.
 */

class Particle {
private:
	int m_Life;	
	glm::vec3 m_Position;	
	glm::vec3 m_Velocity;	
	float m_Mass = 1.0;	
	int MAX_LIFE = 500;
	int MIN_LIFE = 250;

public:

	/* Function: constructor
	 * Usage: Particle p(pos);
	 **********************************************************************
	 * Init particle with initial time.
	 */
	Particle() { }
	Particle(glm::vec3 pos);


	/* Function: exist
	 * Usage: if(p.exist()) { }
	 ***********************************************************************
	 * Judge whether this particle dies. There are two rules:
	 * 1) Out of bound;
	 * 2) Age down to 0.
	 */

	bool exist();


	/* Function: update
	 * Usage: p.update();
	 ***********************************************************************
	 * Update particle' age, position, velocity and acceleration one by one.
	 */

	void update();

	const glm::vec3 &getVelocity() const { return m_Velocity; }
	const glm::vec3 &getPosition() const { return m_Position; }
	const int getLife() const { return m_Life; }
	const int getMinLife() const { return MIN_LIFE; }
};

