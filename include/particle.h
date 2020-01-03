#pragma once
#include "random.h"
#include "constant.h"
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
	int age;		// age
	glm::vec3 p;	// position
	glm::vec3 v;	// velocity
	glm::vec3 a;	// acceleration

public:

	/* Function: constructor
	 * Usage: Particle p(time);
	 **********************************************************************
	 * Init particle with initial time.
	 */

	Particle();


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

	const glm::vec3 &getV() const { return v; }
	const glm::vec3 &getP() const { return p; }
	const glm::vec3 &getA() const { return a; }
	const int getAge() const { return age; }
};


/* Function: randParticleNum
 * Usage: int n = randParticleNum();
 ***********************************************************************
 * Get a random particle number to generate. This number is calculated
 * as follows:
 *	n = average + variance * distribution[-1, 1]
 * In this particle system, it is between 0 and 10, which means every 
 * frame, there are less than 10 new particles generated from the top.
 */

int randParticleNum();