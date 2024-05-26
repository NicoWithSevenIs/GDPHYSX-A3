#include "SimController.hpp"

using namespace controller;

SimController::SimController() {
	this->fTopThreshold = 350.0f;
	this->fBottomThreshold = -350.0f;
	this->fDuration = 0.0f;
	this->bEndSim = false;
}

bool SimController::checkHitTop(Particle* pParticle) {
	float y = pParticle->getPosition()->getY();
	if (y > this->fTopThreshold) {
		return true;
	}
	return false;
}

bool SimController::checkHitBottom(Particle* pParticle) {
	float y = pParticle->getPosition()->getY();
	if (y <= this->fBottomThreshold) {
		return true;
	}
	return false;
}

void SimController::invertVelocity(Particle* pParticle, float fTime) {
	if (this->checkHitTop(pParticle)) {
		pParticle->getVelocity()->setCoordinates(glm::vec3(pParticle->getVelocity()->getX(), pParticle->getVelocity()->getY() * -1.0f, pParticle->getVelocity()->getZ()));
		this->bEndSim = false;
	}

	if (!this->checkHitBottom(pParticle)) {
		this->fDuration += fTime;
	}

	if (this->checkHitBottom(pParticle)) {
		if (this->fDuration > 0.0f) {
			std::cout << "It took " << this->fDuration << " seconds for it to land." << std::endl;
			exit(0);

		}
	}
	
}

