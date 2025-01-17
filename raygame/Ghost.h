#pragma once
#include "Agent.h"
#include "ABDecisions.h"
#include "SeekPathBehavior.h"
#include "GhostDecision.h"

class Maze;

class Ghost : public Agent
{
public:
	/// <param name="x">The x-position</param>
	/// <param name="y">The y-position</param>
	/// <param name="speed">The maximum movement speed (magnitude)</param>
	/// <param name="color">The color in 0xRRGGBBAA</param>
	/// <param name="maze">The maze used for pathfinding</param>
	/// <param name="switchBehaviors">Add behavior based on wether you set value to true or false. true: pathfinding. false: decision Behaviors </param>
	Ghost(float x, float y, float speed, int color, Maze* maze, bool switchBehaviors);
	~Ghost();

	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual void onCollision(Actor* other) override;

	/// <returns>The current target</returns>
	Actor* getTarget();
	/// <summary>
	/// Set the target of the ghost
	/// </summary>
	/// <param name="target">The new target</param>
	void setTarget(Actor* target);

	WanderBehavior* getWander() { return m_wanderBehavior; }
	SeekBehavior* getSeek() { return m_seekBehavior; }

private:
	WanderBehavior* m_wanderBehavior;
	SeekBehavior* m_seekBehavior;
	//WanderDecision m_wanderDecision = new WanderDecision();
	//SeekDecision m_seekDecision = new SeekDecision();
	//ABDecisions* m_ABDecisionBehavior = new ABDecisions(m_wanderBehavior, m_seekBehavior);
	//Decision* m_decisionBehavior = new Decision(m_ABDecisionBehavior);
	GhostDecision* m_ghostDecision;
	SeekPathBehavior* m_pathfindBehavior;
	Maze* m_maze;

	Actor* m_target;
};