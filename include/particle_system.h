#pragma once
#include <vector>
#include "particle.h"

class ParticleSystem {
private:
	std::vector<Particle> m_Particles;
	
	/* Generate number */
	int avg_nParticles = 5;
	int var_nParticles = 5;

	/* Generate square */
	float x_Left = -5.0;
	float x_Right = 5.0;
	float y_Left = 5.0;
	float y_Right = 5.0;
	float z_Left = -5.0;
	float z_Right = 5.0;

	void generateParticles();

	/* Function: randParticleNum
	* Usage: int n = randParticleNum();
	***********************************************************************
	* Get a random particle number to generate. This number is calculated
	* as follows:
	*	n = average + variance * distribution[-1, 1]
	* In this particle system, it is between 0 and 10, which means every
	* frame, there are less than 10 new particles generated from the top.
	*/

	unsigned int randParticleNum();

public:
	ParticleSystem();
	void update();
	const std::vector<Particle> &getParticles() const { return m_Particles; }

};
