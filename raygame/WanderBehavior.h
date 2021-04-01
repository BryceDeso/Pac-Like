#pragma once
#include "SteeringBehavior.h"
class Actor;

class WanderBehavior : public SteeringBehavior
{
public:
	WanderBehavior();
	WanderBehavior(float maxForce);

	void setTarget(Actor* actor) { m_target = actor; }
	Actor* getTarget() { return m_target; }

	void update(Agent* agent, float deltaTime) override;
	void draw(Agent* agent) override;

private:
	Actor* m_target;
	float m_wanderForce;

};