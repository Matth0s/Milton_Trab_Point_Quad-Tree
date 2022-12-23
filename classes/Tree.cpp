/* ************************************************************************** */
/*               ____                  _     _______                          */
/*              / __ \                | |   |__   __|                         */
/*             | |  | |_   _  __ _  __| |______| |_ __ ___  ___               */
/*             | |  | | | | |/ _` |/ _` |______| | '__/ _ \/ _ \              */
/*             | |__| | |_| | (_| | (_| |      | | | |  __/  __/              */
/*              \___\_\\__,_|\__,_|\__,_|      |_|_|  \___|\___|              */
/*                                                                            */
/*               Felipe Patitucci                   - 120022269               */
/*               Igor Torres                        - 119034669               */
/*               Matheus Moreira do Nascimento      - 119042060               */
/*               Pedro Wong                         - 120076810               */
/*               Ruan Felipe da Silva e Sousa       - 119041454               */
/*                                                                            */
/* ************************************************************************** */

#include "Tree.hpp"

Tree::Tree( void ): _root(nullptr) {}


Tree::~Tree( void ) {
	this->_deleteNode(_root);
}

void	Tree::_deleteNode( Node* node ) {

	if (!node)
		return ;
	this->_deleteNode(node->_northWest);
	this->_deleteNode(node->_northEast);
	this->_deleteNode(node->_southWest);
	this->_deleteNode(node->_southEast);
	delete node;

}

void	Tree::insert( Point p ) {

	Node*	node;
	string	direction;

	if (this->has(p) || p.getX() > MAXX || p.getY() > MAXY)
		return ;
	if (!_root) {
		_root = new Node(p, Point(0, 0), Point(MAXX, MAXY));
		return ;
	}
	
	node = _root;
	while (node->relativeDirection(p)) {
		node = node->relativeDirection(p);
	}
	direction = node->_center.relativePosition(p);
	if (direction == "NW")
		node->_northWest = new Node(p, node->_topLeft, node->_center);
	else if (direction == "NE")
		node->_northEast = new Node(p, Point(node->_center.getX(), node->_topLeft.getY()),
							Point(node->_bottomRight.getX(), node->_center.getY()));
	else if (direction == "SW")
		node->_southWest = new Node(p, Point(node->_topLeft.getX(), node->_center.getY()), 
							Point(node->_center.getX(), node->_bottomRight.getY()));
	else
		node->_southEast = new Node(p, node->_center, node->_bottomRight);

}

bool	Tree::_has( Point p, Node* node ) {

	string	direction;
	
	if (!node)
		return (false);

	direction =	node->_center.relativePosition(p);
	if (direction == "NW")
		return this->_has(p, node->_northWest);
	if (direction == "NE")
		return this->_has(p, node->_northEast);
	if (direction == "SW")
		return this->_has(p, node->_southWest);
	if (direction == "SE")
		return this->_has(p, node->_southEast);
	return (true);
}

bool	Tree::has( Point p ) {
	if (_root)
		return this->_has(p, _root);
	return (false);
}
