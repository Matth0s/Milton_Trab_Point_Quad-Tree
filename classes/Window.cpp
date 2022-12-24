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
	_title(), _width(MAXX + 20), _height(MAXY + 20), _closed(false),
	_tree(nullptr),
	_window(nullptr), _renderer(nullptr) {

	if (this->_init())
		_closed = true;
}

Window::Window( string title, int width, int height, Tree* tree ):
	_title(title), _width(width + 20), _height(height + 20), _closed(false),
	_tree(tree), _window(nullptr), _renderer(nullptr) {

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

	SDL_Rect	box;

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	box.w = _width - 16;
	box.h = 5;
	box.x = _width/2 - box.w/2;
	box.y = 10 - box.h/2;
	SDL_RenderFillRect(_renderer, &box);
	box.y = _height - 10 - box.h/2;
	SDL_RenderFillRect(_renderer, &box);
	box.w = 5;
	box.h = _height - 16;
	box.y = _height/2 - box.h/2;
	box.x = 10 - box.w/2;
	SDL_RenderFillRect(_renderer, &box);
	box.x = _width - 10 - box.w/2;
	SDL_RenderFillRect(_renderer, &box);
	SDL_RenderPresent(_renderer);

	return (0);
}

bool	Window::isClosed( void ) {
	return (_closed);
}

void	Window::_handleKeyDown( SDL_Keycode key ) {

	switch (key) {
		case SDLK_p:
			if (_tree)
				_tree->searchWindow(Point(0, 0), Point(MAXX, MAXY));
			break;
		case SDLK_ESCAPE:
			_closed = true;
			break;
		default:
			break;
	}

}

void	Window::pollEvents( void ) {

	SDL_Event	event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				this->_handleKeyDown(event.key.keysym.sym);
				break;
			case SDL_QUIT:
				_closed = true;
				break;
			default:
				break;
		}
	}

}