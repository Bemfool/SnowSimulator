#include "particle_system.h"

ParticleSystem::ParticleSystem() {
	generateParticles();
}


void ParticleSystem::generateParticles() {
	for (unsigned int i = 0; i < randParticleNum(); i++) {
		m_Particles.push_back(Particle(glm::vec3(uniform_random(x_Left, x_Right),
												 uniform_random(y_Left, y_Right),
												 uniform_random(z_Left, z_Right))));
	}
}


void ParticleSystem::update() {
	for (auto it = m_Particles.begin(); it != m_Particles.end(); ) {
		it->update();
		if (!it->exist())
			it = m_Particles.erase(it);
		else
			it++;
	}

	generateParticles();
}


unsigned int ParticleSystem::randParticleNum() {
	return avg_nParticles + var_nParticles * uniform_random(-1.0, 1.0);
}