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

#ifndef WINDOWS_HPP
# define WINDOWS_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_timer.h>

# include "Tree.hpp"
# include <cmath>

class Window
{
	private:

		string			_title;
		bool			_closed;
		int				_zoom;
		Point			_topLeft;
		Point			_bottomRight;

		Tree*			_tree;
		SDL_Window*		_window;
		SDL_Renderer*	_renderer;

	private:

		int			_init( void );
		void		_moveView( Point point, string operatorSimbol );
		void		_printPoints( void );
		void		_handleKeyDown( SDL_Keycode key );
		void		_handleWheel( SDL_MouseWheelEvent wheel );
		void		_handleClick( SDL_MouseButtonEvent click );

		Point		_ScaledPointToRealPoint( Point point );
		Point		_RealPointToScaledPoint( Point point );
		RenderPoint	_RealPointToScaledPoint( RenderPoint point );

		void		_clearWindow( void );
		void		_drawBox( double w, double h, double x, double y );
		void		_drawBorder( void );
		void		_drawPoint( RenderPoint point );
		void		_drawViewPoints( void );

	public:

		Window( void );
		Window( string title, Tree* tree);
		~Window( void );

		bool	isClosed( void );
		void	pollEvents( void );
};

#endif
