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

# include "Tree.hpp"

Tree::Tree( void ): _root(nullptr), _size(0) {}

Tree::Tree( string points ): _root(nullptr), _size(0) {

	size_t	index;

	if (points.size() == 0)
		return ;
	while (points.size() != 0) {
		index = (points.find_first_of(" ") != string::npos)
				? points.find_first_of(" ") : points.size();
		this->insert( Point(points.substr(0, index)));
		points = points.substr(index + 1, points.size());
	}
}

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

int		Tree::size( void ) {
	return (_size);
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


bool	Tree::insert( Point p ) {

	Node*	node;
	Node*	newNode;
	string	direction;

	if (this->has(p)
		|| p.getX() < 0|| p.getX() > WIDTH || p.getY() < 0 || p.getY() > HEIGHT)
		return (false);
	if (!_root) {
		newNode = new Node(p, Point(0, 0), Point(WIDTH, HEIGHT));
		_root = newNode;
	} else {
		node = _root;
		while (node->relativeDirection(p))
			node = node->relativeDirection(p);
		direction = node->_center.relativePosition(p);
		if (direction == "NW") {
			newNode = new Node(p, node->_topLeft, node->_center);
			node->_northWest = newNode;
		} else if (direction == "NE") {
			newNode = new Node(p,
				Point(node->_center.getX(), node->_topLeft.getY()),
				Point(node->_bottomRight.getX(), node->_center.getY()));
			node->_northEast = newNode;
		} else if (direction == "SW") {
			newNode = new Node(p,
				Point(node->_topLeft.getX(), node->_center.getY()),
				Point(node->_center.getX(), node->_bottomRight.getY()));
			node->_southWest = newNode;
		} else {
			newNode = new Node(p, node->_center, node->_bottomRight);
			node->_southEast = newNode;
		}
	}
	_size++;
	return (true);
}

void	Tree::clear( void ) {

	this->_deleteNode(_root);
	_root = nullptr;
	_size = 0;
}

void	Tree::_searchWindow( Point topLeft, Point bottomRight, RenderPoint* points,
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
		points[(*count)++] = RenderPoint(node->_center, node->_topLeft,
										node->_bottomRight);
}

RenderPoint*	Tree::searchWindow( Point topLeft, Point bottomRight ) {

	RenderPoint*	points = new RenderPoint[_size + 1];
	int				count = 0;

	this->_searchWindow(topLeft, bottomRight, points, &count, _root);
	points[count] = RenderPoint(Point(-1,-1), Point(), Point());
	return (points);
}

RenderPoint*	Tree::searchDirection( Point p, string direction ) {

	if (direction == "N")
		return (this->searchWindow(Point(0,0), Point(WIDTH,p.getY())));
	if (direction == "S")
		return (this->searchWindow(Point(0,p.getY()), Point(WIDTH,HEIGHT)));
	if (direction == "W")
		return (this->searchWindow(Point(0,0), Point(p.getX(),HEIGHT)));
	if (direction == "E")
		return (this->searchWindow(Point(p.getX(),0), Point(WIDTH,HEIGHT)));
	if (direction == "NW")
		return (this->searchWindow(Point(0,0), p));
	if (direction == "NE")
		return (this->searchWindow(Point(p.getX(),0), Point(WIDTH,p.getY())));
	if (direction == "SW")
		return (this->searchWindow(Point(0,p.getY()), Point(p.getX(),HEIGHT)));
	if (direction == "SE")
		return (this->searchWindow(p, Point(WIDTH,HEIGHT)));
	return (nullptr);
}
