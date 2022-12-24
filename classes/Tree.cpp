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
		this->insert( Point(points.substr(0, index)), NULL );
		points = points.substr(index + 1, points.size());
	}
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

Tree::~Tree( void ) {
	this->_deleteNode(_root);
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


bool	Tree::insert( Point p, RenderPoint* renderPoint ) {

	Node*	node;
	Node*	newNode;
	string	direction;

	if (this->has(p) || p.getX() > MAXX || p.getY() > MAXY)
		return (false);
	if (!_root) {
		_root = new Node(p, Point(0, 0), Point(MAXX, MAXY));
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
	if (renderPoint) {
		renderPoint->center = newNode->_center;
		renderPoint->topLeft = newNode->_topLeft;
		renderPoint->bottomRight = newNode->_bottomRight;
	}
	_size++;
	return (true);
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
