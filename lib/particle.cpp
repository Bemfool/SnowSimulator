#include "particle.h"


Particle::Particle() {
	/* Init age */
	m_Life = uniform_random(MIN_AGE, MAX_AGE);
	/* Init position */
	m_Position = glm::vec3(uniform_random(X_LEFT_BOUND, X_RIGHT_BOUND), 
				  Y_UPPER_BOUND, 
				  uniform_random(Z_FAR_BOUND, Z_CLOSE_BOUND));
	/* Init velocity */
	m_Velocity = glm::vec3(0.0, -0.018, 0.0);
}


bool Particle::exist() {
	return m_Position.y > Y_LOWER_BOUND & m_Life > 0;
}


void Particle::update() {
	float deltaT = Environment::getInstance().getInterval();
	/* Update age */
	m_Life--;
	/* Update position */
	m_Position = m_Position + m_Velocity * deltaT;
	/* Update velocity */
	Environment::getInstance().setRndWind();
	glm::vec3 force;
	glm::vec3 gravity = Environment::getInstance().getGravity() * m_Mass;
	glm::vec3 airFriction = glm::vec3(0.0, Environment::getInstance().getK() * glm::pow(glm::length(m_Velocity), 2), 0.0);
	if (-gravity.y < airFriction.y) 
		force = Environment::getInstance().getWind();
	else 
		force = gravity + airFriction + Environment::getInstance().getWind();
	glm::vec3 acc = force / m_Mass;
	m_Velocity = m_Velocity + acc * deltaT;
}


int randParticleNum() {
	return AVG_PARTICLE_NUM + VAR_PARTICLE_NUM * uniform_random(-1.0, 1.0);
}