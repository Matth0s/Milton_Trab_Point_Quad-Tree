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

# include "Window.hpp"

Window::Window( void ):
	_title(), _width(800), _height(600), _closed(false),
	_window(nullptr), _renderer(nullptr) {

	if (this->_init())
		_closed = true;
}

Window::Window( string title, int width, int height ):
	_title(title), _width(width), _height(height), _closed(false),
	 _window(nullptr), _renderer(nullptr) {

	if (this->_init())
		_closed = true;
}

Window::~Window( void ) {

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();

}

int		Window::_init( void ) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "error: " << SDL_GetError() << endl;
		return (1);
	}
	_window = SDL_CreateWindow(_title.c_str(),
		SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED,
		_width, _height, SDL_WINDOW_SHOWN);
	if (!_window) {
		cout << "error: " << SDL_GetError() << endl;
		return (2);
	}
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer) {
		cout << "error: " << SDL_GetError() << endl;
		return (3);
	}

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);

//	SDL_Rect	box;

//	box.w = 5;
//	box.h = 5;
//	box.x = 300 - box.w/2;
//	box.y = 300 - box.h/2;

//	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
//	SDL_RenderFillRect(_renderer, &box);
//	SDL_RenderPresent(_renderer);

	return (0);
}

bool	Window::isClosed( void ) {
	return (_closed);
}

void	Window::pollEvents( void ) {

	SDL_Event	event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					_closed = true;
				break;
			case SDL_QUIT:
				_closed = true;
				break;
			default:
				break;
		}
	}

}