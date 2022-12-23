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

#ifndef NODE_HPP
#define NODE_HPP

#include "Point.hpp"

class Node
{
	private:

		Point	_center;

		Point	_topLeft;
		Point	_bottomRight;

		Node*	_northWest;
		Node*	_northEast;
		Node*	_southWest;
		Node*	_southEast;

	public:

		Node( void );
		Node( Point center, Point topLeft, Point bottomRight );
		~Node( void );

		Node	&operator=( const Node &rhs );

		friend	ostream &operator<<(ostream &output, const Node &rhs);
		friend	class Tree;

		Node*	relativeDirection( Point p );
};

#endif
