#include "particle.h"


Particle::Particle(glm::vec3 pos) {
	/* Init age */
	m_Life = uniform_random(MIN_LIFE, MAX_LIFE);
	/* Init position */
	m_Position = pos;
	/* Init velocity */
	m_Velocity = glm::vec3(0.0, -0.018, 0.0);
}



bool Particle::exist() {
	return Environment::getInstance().outOfBound(m_Position) & (m_Life > 0);
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
	if (-gravity.y < airFriction.y) {
		force = Environment::getInstance().getWind();
		//std::cout << "!!" << std::endl;
	}
	else
		force = gravity + airFriction + Environment::getInstance().getWind();
	glm::vec3 acc = force / m_Mass;
	m_Velocity = m_Velocity + acc * deltaT;
}

