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
# define TREE_HPP

# define WIDTH 800
# define HEIGHT 450

# include "Node.hpp"

struct RenderPoint
{
	Point	center;
	Point	topLeft;
	Point	bottomRight;

	RenderPoint( void ): center(), topLeft(), bottomRight() {};
	RenderPoint( Point center, Point topLeft, Point bottomRight ):
		center(center), topLeft(topLeft), bottomRight(bottomRight) {};

};

class Tree
{
	private:

		Node*	_root;
		int		_size;

		void	_deleteNode( Node* node );
		bool	_has( Point p, Node* node );
		void	_searchWindow( Point topLeft, Point bottomRight,
								RenderPoint* points, int* count, Node* node );
	public:

		Tree( void );
		Tree( string points );
		~Tree( void );

		int				size( void );
		bool			has( Point p );
		bool			insert( Point p );
		void			clear( void );
		RenderPoint*	searchWindow( Point topLeft, Point bottomRight );
		RenderPoint*	searchDirection( Point p, string direction );
};

#endif
