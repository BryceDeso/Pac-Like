#pragma once
#include "Behavior.h"

enum GhostState
{
	WANDER,
	SEEK
};

class WanderBehavior;
class SeekBehavior;

class GhostDecision : public Behavior
{
public:
	GhostDecision(SeekBehavior* seekBehavior, WanderBehavior* wanderBehavior, GhostState currentState);

	bool checkPlayerInSight(Agent* owner);

	void update(Agent* agent, float deltaTime) override;

private:
	GhostState m_currentState;
	WanderBehavior* m_wander;
	SeekBehavior* m_seek;
	float m_visionRadius = 100;
};

