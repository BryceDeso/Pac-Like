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

#### Problems:

##### Dijkstra not working properly.
    The problem for this is my varibale currentEdgeNode being set to null.
    Everytime I would try and implement something new to a class to fix this bug it would result in