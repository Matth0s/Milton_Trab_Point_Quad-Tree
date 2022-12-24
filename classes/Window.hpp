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

# include <iostream>

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_timer.h>

using namespace std;

class Window
{
	private:

		string	_title;
		int		_width;
		int		_height;
		bool	_closed;

		SDL_Window*		_window;
		SDL_Renderer*	_renderer;

		int		_init( void );

	public:

		Window( void );
		Window( string title, int width, int height );
		~Window( void );

		bool	isClosed( void );
		void	pollEvents( void );
};

#endif
