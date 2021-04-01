#pragma once
#include "Behavior.h"

enum GhostState
{
	WANDER,
	SEEK
};

class WanderBehavior;
class SeekBehavior;
class SeekPathBehavior;

class GhostDecision : public Behavior
{
public:
	void start();

	bool checkPlayerInSight(Agent* owner);

	void update(Agent* agent, float deltaTime) override;

private:
	GhostState m_currentState;
	WanderBehavior* m_wander;
	SeekBehavior* m_seek;
	float m_visionRadius = 100;
};

