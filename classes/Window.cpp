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
	_title(), _width(WIDTH + 20), _height(HEIGHT + 20), _closed(false),
	_topLeft(0,0), _bottomRight(WIDTH, HEIGHT), _zoom(1),
	_tree(nullptr), _window(nullptr), _renderer(nullptr) {

	if (this->_init())
		_closed = true;
}

Window::Window( string title, Tree* tree ):
	_title(title), _width(WIDTH + 20), _height(HEIGHT + 20), _closed(false),
	_topLeft(0,0), _bottomRight(WIDTH, HEIGHT), _zoom(1),
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
	this->_clearWindow();
	this->_drawViewPoints();
	return (0);
}

bool	Window::isClosed( void ) {
	return (_closed);
}

void	Window::pollEvents( void ) {

	SDL_Event	event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				this->_handleClick(event.button);
				break;
			case SDL_KEYDOWN:
				this->_handleKeyDown(event.key.keysym.sym);
				break;
			case SDL_MOUSEWHEEL:
				this->_handleWheel(event.wheel);
				break;
			case SDL_QUIT:
				_closed = true;
				break;
			default:
				break;
		}
	}
}

void	Window::_handleKeyDown( SDL_Keycode key ) {

	RenderPoint*	points = nullptr;
	int				count = 0;

	switch (key) {
		case SDLK_UP:
			cout << "UP" << endl;
			break;
		case SDLK_DOWN:
			cout << "DOWN" << endl;
			break;
		case SDLK_LEFT:
			cout << "LEFT" << endl;
			break;
		case SDLK_RIGHT:
			cout << "RIGHT" << endl;
			break;
		case SDLK_p:
			if (_tree) {
				points = _tree->searchWindow(Point(0, 0), Point(WIDTH, HEIGHT));
				while (true) {
					if (points[count].center.getX() == -1)
						break;
					cout << points[count].center << "   ";
					count++;
				}
				if (count == 0)
					cout << "!! Empty Tree !!";
				cout << endl;
				delete[] points;
			}
			break;
		case SDLK_c:
			_tree->clear();
			this->_clearWindow();
			break;
		case SDLK_ESCAPE:
			_closed = true;
			break;
		default:
			break;
	}
}

void	Window::_handleWheel( SDL_MouseWheelEvent wheel ) {

	if(wheel.y > 0)
		_zoom = (_zoom ) ? _zoom + 5 : _zoom + 5;
	else if(wheel.y < 0)
		_zoom = (_zoom - 5 > 1 ) ? _zoom - 5 : 1;
	cout << "ZOOM: " << _zoom << endl;
}

void	Window::_handleClick( SDL_MouseButtonEvent click ) {

	RenderPoint	point;

	if (_tree->insert(Point(click.x - 10, click.y - 10), &point)) {
		this->_drawViewPoints();
		cout << point.center << endl;
	}
}

void	Window::_clearWindow( void ) {

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
	this->_drawBorder();
}

void	Window::_drawBorder( void ) {

	SDL_Rect	box;

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
}

void	Window::_drawPoint( RenderPoint point ) {

	SDL_Rect	box;

	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	box.w = point.bottomRight.getX() - point.topLeft.getX();
	box.h = 3;
	box.x = point.topLeft.getX() + 10;
	box.y = point.center.getY() + 10 - box.h/2;
	SDL_RenderFillRect(_renderer, &box);
	box.w = 3;
	box.h = point.bottomRight.getY() - point.topLeft.getY();
	box.x = point.center.getX() + 10 - box.w/2;
	box.y = point.topLeft.getY() + 10;
	SDL_RenderFillRect(_renderer, &box);
	SDL_RenderPresent(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	box.w = 5;
	box.h = 5;
	box.x = point.center.getX() + 10 - box.w/2;
	box.y = point.center.getY() + 10 - box.h/2;
	SDL_RenderFillRect(_renderer, &box);
	SDL_RenderPresent(_renderer);
}

void	Window::_drawViewPoints( void ) {

	RenderPoint*	points = _tree->searchWindow(_topLeft, _bottomRight);
	int				count = 0;

	this->_drawBorder();
	while (true) {
		if (points[count].center.getX() == -1)
			break;
		this->_drawPoint(points[count]);
		count++;
	}
	delete[] points;
}
