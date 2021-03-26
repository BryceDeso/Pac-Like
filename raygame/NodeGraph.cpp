#include "NodeGraph.h"
#include <raylib.h>

std::deque<NodeGraph::Node*> NodeGraph::findPath(Node* start, Node* end)
{
	// Find a path from start to end (The current implementation is obviously insufficient)
	std::deque<Node*> path;
	path.push_back(start);
	path.push_back(start);
	path.push_back(end);
	return path;

	////Check if the start or the goal pointer is null
	//if (!start || !end)
	//{
	//	//return an empty list
	//	return std::deque<Node*>();
	//}
	//	
	////Create a node pointer that will be act as an iterator for the graph
	//Node* currentNode = start;

	////Create an open list
	//std::deque<Node*> openList;
	////Create a closed list
	//std::deque<Node*> closedList;

	////Add start to the open list
	//openList.push_front(start);

	////Loop while the open list is not empty
	//while (!openList.empty())
	//{
	//	//Sort the items in the open list by the g score
	//	sort(openList);

	//	//Set the iterator to be the first item in the open list
	//	openList.push_front(currentNode);

	//	//Check if the iterator is pointing to the goal node
	//	if (currentNode == end)
	//	{
	//		break;
	//	}

	//	//Pop the first item off the open list
	//	openList.pop_front();

	//	//Add the first item to the closed list
	//	closedList.push_front(currentNode);

	//	//Loop through all of the edges for the iterator
	//	for (int i = 0; i < currentNode->connections.size(); i++)
	//	{
	//		//Create a node pointer to store the other end of the edge
	//		Node* currentEdgeEnd = nullptr;
	//		if (currentNode->connections[i].target != currentNode)
	//		{
	//			currentEdgeEnd = currentNode->connections[i].target;
	//		}

	//		//Check if node at the end of the edge is in the closed list
	//		if (!checkDeque(closedList, currentEdgeEnd))
	//		{
	//			//Create an int and set it to be the g score of the iterator plus the cost of the edge
	//			float gScore = currentNode->gScore + currentNode->connections[i].cost;
	//			float hScore = (currentNode->position - end->position).getMagnitude();
	//			float fScore = gScore + hScore;

	//			//Check if the node at the end ofthe edge is in the open list
	//			if (!checkDeque(openList, currentEdgeEnd))
	//			{
	//				//Set the nodes g score to be the g score calculated earlier
	//				currentEdgeEnd->gScore = gScore;
	//				currentEdgeEnd->hScore = hScore;
	//				currentEdgeEnd->fscore = gScore + hScore;

	//				//Set the nodes previous to be the iterator
	//				currentEdgeEnd->previous = currentNode;

	//				//Add the node to the open list
	//				openList.push_front(currentEdgeEnd);
	//			}
	//			//Otherwise if the g score is less than the node at the end of the edge's g score...
	//			else if (fScore < currentEdgeEnd->fscore)
	//			{
	//				//Set its g score to be the g score calculated earlier
	//				currentEdgeEnd->gScore = gScore;
	//				currentEdgeEnd->hScore = hScore;

	//				//Set its previous to be the current node
	//				currentEdgeEnd->previous = currentNode;
	//			}
	//		}
	//	}
	//}
	//std::deque<Node*> path;
	//while (currentNode != start)
	//{
	//	path.push_front(currentNode);
	//	currentNode = currentNode->previous;
	//}
	//return path;
}

void NodeGraph::drawGraph(Node* start)
{
	std::deque<Node*>* drawnList = new std::deque<Node*>();
	drawConnectedNodes(start, drawnList);
	delete drawnList;
}

void NodeGraph::drawNode(Node* node, int color)
{
	static char buffer[10];
	sprintf_s(buffer, "%.0f", node->gScore);

	//Draw the circle for the outline
	DrawCircle((int)node->position.x, (int)node->position.y, 16, GetColor(color));
	//Draw the inner circle
	DrawCircle((int)node->position.x, (int)node->position.y, 14, BLACK);
	//Draw the text
	DrawText(buffer, (int)node->position.x, (int)node->position.y, 24, RAYWHITE);
}

void NodeGraph::drawConnectedNodes(Node* node, std::deque<Node*>* drawnList)
{
	//drawNode(node);
	drawnList->push_back(node);

	//For each Edge in this node's connections
	for (Edge e : node->connections) {
		//Draw the Edge
		DrawLine((int)node->position.x, (int)node->position.y, (int)e.target->position.x, (int)e.target->position.y, WHITE);
		//Draw the cost
		MathLibrary::Vector2 costPos = { (node->position.x + e.target->position.x) / 2, (node->position.y + e.target->position.y) / 2 };
		static char buffer[10];
		sprintf_s(buffer, "%.0f", e.cost);
		DrawText(buffer, (int)costPos.x, (int)costPos.y, 16, RAYWHITE);
		//Draw the target node
		if (std::find(drawnList->begin(), drawnList->end(), e.target) == drawnList->end()) {
			drawConnectedNodes(e.target, drawnList);
		}
	}
}

bool NodeGraph::checkDeque(std::deque<Node*> deque, NodeGraph::Node* node)
{
	{
		//For the size of a deque, check deque at the index of i. 
		for (int i = 0; i < deque.size(); i++)
		{
			//if deque at the index of i is equal to node, return true.
			if (deque[i] == node)
			{
				return true;
			}
		}
		return false;
	}
}

std::deque<NodeGraph::Node*> NodeGraph::sort(std::deque<Node*> deque)
{
	//Bubble sort
	for (int i = 0; i < deque.size(); i++)
	{
		for (int j = deque.size() - 1; j > i; j--)
		{
			if (deque[j] < deque[j - 1])
			{
				NodeGraph::Node* temp = deque[j];
				deque[j] = deque[j - 1];
				deque[j - 1] = temp;
			}
		}
	}
	return deque;
}