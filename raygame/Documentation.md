| Bryce Deshotel|
|:---|
|s208069|
|Computer Programming|
|Assessment-1 Documentation|

### Key AI Mechanics

##### Seek Behavior:

The enemy is always aware of the player's current position and will seek to it.

##### Flee Behavior:

If the enemy sees the player they will begin to flee away from its current position.

##### PathFinding:

They enemy should use this when seeking the player as well as fleeing from the player.
The algorithim implemented was A*.

### Known Problems:

##### Dijkstra not working properly.
    The problem for this is the open list is never emptied and will continue to iterate though the while loop.

##### StateMachine not working properly.

    While it will call the behavior for the state machine it effectively does nothing due to not getting it to switch properly and not getting the force to setfor flee.
    As for the force not being properly set for flee, I think that is something to do with how I implemented my code with Van's and not fully understanding they're implementations.