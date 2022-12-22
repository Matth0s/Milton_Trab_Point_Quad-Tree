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

#include "Point.hpp"

Point::Point( void ): _x(0), _y(0) {}

Point::Point( const Point& src ): _x(src._x), _y(src._y) {}

Point::Point( double x, double y ): _x(x), _y(y) {}

Point::~Point( void ) {}

Point&	Point::operator=( const Point& rhs )
{
	if (this == &rhs)
		return (*this);

	this->_x = rhs._x;
	this->_y = rhs._y;
	return (*this);
}

ostream&	operator<<( ostream& output, const Point& rhs )
{
	output << "[" << rhs._x << ", " << rhs._y << "]";
	return (output);
}

double	Point::getX( void ) {
	return (_x);
}

double	Point::getY( void ) {
	return (_y);
}

string	Point::relativePosition( Point p ) {

	string	result;

	if (p._y < _y)
		result += "N";
	else 
		result += "S";

	if (p._x < _x)
		result += "W";
	else 
		result += "E";

	if (p._x == _x && p._y == _y)
		result = "EQUAL";

	return result;
}
