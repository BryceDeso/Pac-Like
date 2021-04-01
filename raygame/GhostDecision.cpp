#include "GhostDecision.h"
#include "SeekPathBehavior.h"
#include "FleeBehavior.h"
#include "SeekBehavior.h"
#include "SeekPathBehavior.h"
#include "WanderBehavior.h"
#include "Ghost.h"


void GhostDecision::start()
{
	m_currentState = WANDER;

	m_seek->setForceScale(5);
	m_wander->setForceScale(5);
}

bool GhostDecision::checkPlayerInSight(Agent* agent)
{
	// Cast owner to Ghost*
	Ghost* ghost = dynamic_cast<Ghost*>(agent);
	if (!ghost)
	{
		return false;
	}
		
	// If the distance between the player and the ghost is less than m_visionDistance return true
	if ((ghost->getTarget()->getWorldPosition() - ghost->getWorldPosition()).getMagnitude() < m_visionRadius)
	{
		return true;
	}
	return false;
}

void GhostDecision::update(Agent* agent, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(agent);

	//Create a switch statment for the state machine
	switch (m_currentState)
	{
	case WANDER:
		//The Switch should transition to the wander state if the target is not in sight
		//You can set the wander force to be whatever value as you see fit but be sure to set seekforce to 0
		if (!checkPlayerInSight(agent))
		{
			m_wander->setEnabled(true);
			m_seek->setEnabled(false);

			m_currentState = SEEK;
		}
		break;
	case SEEK:
		//the switch should transition to seek state if the target is in sight
		//You can set the seek force to be whatever you want it to be but be sure to set wander force to 0
		if (checkPlayerInSight(agent))
		{
			m_seek->setEnabled(true);
			m_wander->setForceScale(false);

			m_currentState = WANDER;
		}
		break;
	}
}
