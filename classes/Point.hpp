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

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cstdlib>

using namespace std;

class Point
{
	private:

		int	_x;
		int	_y;

	public:

		Point( void );
		Point( const Point& src );
		Point( int x, int y );
		Point( string point );
		~Point( void );

		Point&	operator=( const Point& rhs );
		Point&	operator+=( const Point& rhs );
		Point&	operator-=( const Point& rhs );

		friend	ostream&	operator<<( ostream& output, const Point& rhs );

		int		getX( void );
		int		getY( void );

		string	relativePosition( Point p );
};

#endif
