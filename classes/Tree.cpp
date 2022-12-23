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

Tree::Tree( void ): _root(nullptr), _size(0) {}

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
		_size++;
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
	_size++;

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

void	Tree::_searchWindow( Point topLeft, Point bottomRight, Point* points, 
								int* count , Node* node) {
	if (!node)
		return ;

	this->_searchWindow(topLeft, bottomRight, points, count, node->_northWest);
	this->_searchWindow(topLeft, bottomRight, points, count, node->_northEast);
	this->_searchWindow(topLeft, bottomRight, points, count, node->_southWest);
	this->_searchWindow(topLeft, bottomRight, points, count, node->_southEast);

	if (topLeft.getX() <= node->_center.getX() 
			&& bottomRight.getX() >= node->_center.getX() 
			&& topLeft.getY() <= node->_center.getY() 
			&& bottomRight.getY() >= node->_center.getY())
		points[(*count)++] = node->_center;
}

void	Tree::searchWindow( Point topLeft, Point bottomRight ) {
	
	Point*	points = new Point[_size];
	int		count = 0;

	this->_searchWindow(topLeft, bottomRight, points, &count, _root);

	while (count-- > 0)
		cout << points[count] << "  ";
	cout << endl;

	delete[] points;

}

void	Tree::searchDirection( Point p, string direction ) {

	if (direction == "N")
		this->searchWindow(Point(0,0), Point(MAXX,p.getY()));
	else if (direction == "S")
		this->searchWindow(Point(0,p.getY()), Point(MAXX,MAXY));
	else if (direction == "W")
		this->searchWindow(Point(0,0), Point(p.getX(),MAXY));
	else if (direction == "E")
		this->searchWindow(Point(p.getX(),0), Point(MAXX,MAXY));
	else if (direction == "NW")
		this->searchWindow(Point(0,0), p);
	else if (direction == "NE")
		this->searchWindow(Point(p.getX(),0), Point(MAXX,p.getY()));
	else if (direction == "SW")
		this->searchWindow(Point(0,p.getY()), Point(p.getX(),MAXY));
	else if (direction == "SE")
		this->searchWindow(p, Point(MAXX,MAXY));
	else
		cout << "Not a valid direction" << endl;
}
