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

#ifndef TREE_HPP
#define TREE_HPP

#define MAXX 160
#define MAXY 90

#include "Node.hpp"

class Tree
{
	private:

		Node*	_root;
		int		_size;

		void	_deleteNode( Node* node );
		bool	_has( Point p, Node* node );
		void	_searchWindow( Point topLeft, Point bottomRight, Point* points,
								int* count, Node* node );

	public: 

		Tree( void );
		~Tree( void );

		void	insert( Point p );
		bool	has( Point p );
		void	searchWindow( Point topLeft, Point bottomRight );
		void	searchDirection( Point p, string direction );

};

#endif
