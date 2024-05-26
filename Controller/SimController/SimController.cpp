#include "SimController.hpp"

using namespace controller;

SimController::SimController() {
	this->fTopThreshold = 350.0f;
	this->fBottomThreshold = 350.0f;
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
	if (y > this->fBottomThreshold) {
		return true;
	}
	return false;
}

void SimController::invertVelocity(Particle* pParticle) {
	if (this->checkHitTop(pParticle)) {
		pParticle->getVelocity()->setCoordinates(glm::vec3(pParticle->getVelocity()->getX(), pParticle->getVelocity()->getY() * -1.0f, pParticle->getVelocity()->getZ()));
	}
}

