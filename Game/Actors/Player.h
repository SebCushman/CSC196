#pragma once
#include "Object/Actor.h"

namespace nc {
	class Player : public Actor {
	public:
		Player() {}
		virtual ~Player() {}

		virtual bool Load(const std::string& filename) override;
		virtual void Update(float dt) override;

	protected:
		// thrust (float)
		float m_thrust{0.0f};
		// rotation rate (float)
		float m_angle{0.0f};
		// velocity (Vector2)
		nc::Vector2 m_velocity;
	};
}