#pragma once
#include "Behavior.h"

enum GhostState
{
	SEEK,
	FLEE
};

class FleeBehavior;
class SeekBehavior;
class SeekPathBehavior;

class GhostDecision : public Behavior
{
public:
	GhostDecision();

	bool checkPlayerInSight(Agent* owner);

	void update(Agent* agent, float deltaTime) override;

private:
	SeekPathBehavior* m_seekPathBehavior;
	GhostState m_currentState;
	FleeBehavior* m_flee;
	SeekBehavior* m_seek;
	float m_visionRadius = 100;
};

