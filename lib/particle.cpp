#include "particle.h"


Particle::Particle() {
	/* Init age */
	age = uniform_random(MIN_AGE, MAX_AGE);
	/* Init position */
	p = glm::vec3(uniform_random(X_LEFT_BOUND, X_RIGHT_BOUND), 
				  Y_UPPER_BOUND, 
				  uniform_random(Z_FAR_BOUND, Z_CLOSE_BOUND));
	/* Init velocity */
	v = glm::vec3(0.0, -0.018, 0.0);
	/* Init acceleration */
	a = glm::vec3(normal_random(0, 0.001), 0, normal_random(0, 0.001));
}


bool Particle::exist() {
	return p.y > Y_LOWER_BOUND & age > 0;
}


void Particle::update() {
	/* Update age */
	age--;
	/* Update position */
	p = p + v * DT + 0.5f * a * DT * DT;
	/* Update velocity */
	v = v + a * DT;
	/* Update acceleration */
	a = glm::vec3(normal_random(0.0, 0.001), 0.0, normal_random(0.0, 0.001));
}


int randParticleNum() {
	return AVG_PARTICLE_NUM + VAR_PARTICLE_NUM * uniform_random(-1.0, 1.0);
}