### Known Problems:

##### Dijkstra not working properly.
    The problem for this is the open list is never emptied and will continue to iterate though the while loop.

##### StateMachine not working properly.

    While it will call the behavior for the state machine it effectively does nothing due to not getting it to switch properly and not getting the force to setfor flee.
    As for the force not being properly set for flee, I think that is something to do with how I implemented my code with Van's and not fully understanding they're implementations.