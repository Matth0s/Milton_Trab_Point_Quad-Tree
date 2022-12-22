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
	_center(), _topRight(), _bottomLeft(),
	_parent(nullptr),
	_northWest(nullptr), _northEast(nullptr),
	_southWest(nullptr), _southEast(nullptr) 
	{}

Node::Node( const Node& src )
: Node() 
{ this->operator=(src); }

Node::Node( Point center, Point topRight, Point bottomLeft , Node* parent ):
	_center(center), _topRight(topRight), _bottomLeft(bottomLeft), 
	_parent(parent)
	,
	_northWest(nullptr), _northEast(nullptr),
	_southWest(nullptr), _southEast(nullptr)
	{}

Node::~Node( void ) {}

Node&	Node::operator=( const Node& rhs )
{
	if (this == &rhs)
		return (*this);

	this->_center = rhs._center;
	this->_topRight = rhs._topRight;
	this->_bottomLeft = rhs._bottomLeft;

	this->_parent = rhs._parent;
	this->_northWest = rhs._northWest;
	this->_northEast = rhs._northEast;
	this->_southWest = rhs._southWest;
	this->_southEast = rhs._southEast;

	return (*this);
}

// ostream&	operator<<( ostream& output, const Node& rhs )
// {
// 	output << "[" << rhs._x << ", " << rhs._y << "]";
// 	return (output);
// }
