#pragma once

#include "../../Physics/Component/Particle/Particle.hpp"

namespace controller {
	using namespace component;
	class SimController {
		private:
			float fTopThreshold;
			float fBottomThreshold;
		public:
			SimController();
		private:
			bool checkHitTop(Particle* pParticle);
			bool checkHitBottom(Particle* pParticle);
		public:
			void invertVelocity(Particle* pParticle);

	};
}

