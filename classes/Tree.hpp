/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Barney e Seus Amigos  <B.S.A@students>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2022/12/23 16:01:01 by Barney e Se      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*               Ruan Felipe da Silva e Sousa       - 119041454               */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# define MAXX 800
# define MAXY 450

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
		void	_searchWindow( Point topLeft, Point bottomRight, Point* points,
								int* count, Node* node );

		void	_getRenderPoints( RenderPoint* points, int* count, Node* node );
	public:

		Tree( void );
		Tree( string points );
		~Tree( void );

		int			size( void );
		bool		has( Point p );
		bool		insert( Point p, RenderPoint* renderPoint );
		void		searchWindow( Point topLeft, Point bottomRight );
		void		searchDirection( Point p, string direction );

		RenderPoint*	getRenderPoints( void );

};

#endif
