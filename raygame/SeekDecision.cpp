#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "Ghost.h"
#include "SeekDecision.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	Ghost* enemy = dynamic_cast<Ghost*>(agent);

	if (enemy)
	{
		enemy->getSeek()->setEnabled(true);
		enemy->getWander()->setEnabled(false);
	}
}