#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "Ghost.h"
#include "WanderDecision.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime)
{
	Ghost* ghost = dynamic_cast<Ghost*>(agent);

	if (!ghost)
	{
		ghost->getWander()->setEnabled(true);
		ghost->getSeek()->setEnabled(false);
	}
}