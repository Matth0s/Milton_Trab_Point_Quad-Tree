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

#include "Node.hpp"

Node::Node( void ):
	_center(), _topLeft(), _bottomRight(),
	_northWest(nullptr), _northEast(nullptr),
	_southWest(nullptr), _southEast(nullptr)
	{}

Node::Node( Point center, Point topLeft, Point bottomRight ):
	_center(center), _topLeft(topLeft), _bottomRight(bottomRight),
	_northWest(nullptr), _northEast(nullptr),
	_southWest(nullptr), _southEast(nullptr)
	{}

Node::~Node( void ) {}

Node&	Node::operator=( const Node& rhs )
{
	if (this == &rhs)
		return (*this);

	this->_center = rhs._center;
	this->_topLeft = rhs._topLeft;
	this->_bottomRight = rhs._bottomRight;

	this->_northWest = rhs._northWest;
	this->_northEast = rhs._northEast;
	this->_southWest = rhs._southWest;
	this->_southEast = rhs._southEast;

	return (*this);
}

ostream&	operator<<( ostream& output, const Node& rhs )
{
	output << rhs._center;
	return (output);
}

Node*	Node::relativeDirection( Point p ) {

	string	direction = _center.relativePosition(p);

	if (direction == "NW")
		return (_northWest);
	if (direction == "NE")
		return (_northEast);
	if (direction == "SW")
		return (_southWest);
	if (direction == "SE")
		return (_southEast);
	return (_southEast);
}
