#pragma once
#include "ABDecisions.h"
class SeekDecision : public ABDecisions
{
	ABDecisions::ABDecisions;
	void makeDecision(Agent* agent, float deltaTime) override;
};

