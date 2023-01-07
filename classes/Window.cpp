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
	_title(), _closed(false), _zoom(1),
	_topLeft(0,0), _bottomRight(WIDTH, HEIGHT),
	_tree(nullptr), _window(nullptr), _renderer(nullptr) {

	if (this->_init())
		_closed = true;
}

Window::Window( string title, Tree* tree ):
	_title(title), _closed(false), _zoom(1),
	_topLeft(0,0), _bottomRight(WIDTH, HEIGHT),
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
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
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

void	Window::_moveView( Point point, string operatorSimbol ) {

	if (operatorSimbol == "+=") {
		_topLeft += point;
		_bottomRight += point;
	}
	else {
		_topLeft -= point;
		_bottomRight -= point;
	}
	this->_clearWindow();
	this->_drawViewPoints();
}

void	Window::_printPoints( void ) {

	RenderPoint*	points = nullptr;
	int				count = 0;

	if (_tree) {
		cout << "Points in QuadTree:   ";
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
}

void	Window::_handleKeyDown( SDL_Keycode key ) {

	switch (key) {
		case SDLK_UP:
			this->_moveView(Point(0, 21 - _zoom), "-=");
			break;
		case SDLK_DOWN:
			this->_moveView(Point(0, 21 - _zoom), "+=");
			break;
		case SDLK_LEFT:
			this->_moveView(Point(21 - _zoom, 0), "-=");
			break;
		case SDLK_RIGHT:
			this->_moveView(Point(21 - _zoom, 0), "+=");
			break;
		case SDLK_r:
			_topLeft = Point(0, 0);
			_bottomRight = Point(WIDTH, HEIGHT);
			_zoom = 1;
			this->_clearWindow();
			this->_drawViewPoints();
			break;
		case SDLK_p:
			this->_printPoints();
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

	if(wheel.y > 0 && _bottomRight.getX() - _topLeft.getX() > 40) {
		_topLeft += Point(20, 20 * HEIGHT / WIDTH);
		_bottomRight -= Point(20, 20 * HEIGHT / WIDTH);
		_zoom++;
	} else if(wheel.y < 0) {
		_topLeft -= Point(20, 20 * HEIGHT / WIDTH);
		_bottomRight += Point(20, 20 * HEIGHT / WIDTH);
		_zoom--;
	}
	cout << "Zoom:  " << _zoom << "x" << endl;
	this->_clearWindow();
	this->_drawViewPoints();
}

void	Window::_handleClick( SDL_MouseButtonEvent click ) {

	Point		scaledPoint;

	scaledPoint = _ScaledPointToRealPoint(Point(click.x, click.y));
	if (_tree->insert(scaledPoint)) {
		this->_drawViewPoints();
		cout << "New Point:  " << scaledPoint << endl;
	}
}

Point	Window::_ScaledPointToRealPoint( Point point ) {

	double	x;
	double	y;

	x = point.getX() * (_bottomRight.getX() - _topLeft.getX()) / WIDTH;
	y = point.getY() * (_bottomRight.getY() - _topLeft.getY()) / HEIGHT;
	return (Point(x + _topLeft.getX(), y + _topLeft.getY()));
}

Point	Window::_RealPointToScaledPoint( Point point ) {

	double	x;
	double	y;

	x = (point.getX() - _topLeft.getX()) * WIDTH
		/ (_bottomRight.getX() - _topLeft.getX());
	y = (point.getY() - _topLeft.getY()) * HEIGHT
		/ (_bottomRight.getY() - _topLeft.getY());
	return (Point(x, y));
}

RenderPoint	Window::_RealPointToScaledPoint( RenderPoint point ) {

	Point	topLeft;
	Point	center;
	Point	bottomRight;

	topLeft = this->_RealPointToScaledPoint(point.topLeft);
	center = this->_RealPointToScaledPoint(point.center);
	bottomRight = this->_RealPointToScaledPoint(point.bottomRight);

	return (RenderPoint(center, topLeft, bottomRight));
}

void	Window::_clearWindow( void ) {

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
	this->_drawBorder();
}

void	Window::_drawBox( double w, double h, double x, double y ) {

	SDL_Rect	box;

	box.w = round(w);
	box.h = round(h);
	box.x = round(x - w/2);
	box.y = round(y - h/2);
	SDL_RenderFillRect(_renderer, &box);
}

void	Window::_drawBorder( void ) {

	Point		center;
	int			w;
	int			h;

	w = WIDTH * WIDTH / (_bottomRight.getX() - _topLeft.getX());
	h = HEIGHT * HEIGHT / (_bottomRight.getY() - _topLeft.getY());
	center = this->_RealPointToScaledPoint(Point((WIDTH)/2, (HEIGHT)/2));

	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	this->_drawBox(w + 4, 5, center.getX(), center.getY() - h/2);
	this->_drawBox(w + 4, 5, center.getX(), center.getY() + h/2);
	this->_drawBox(5, h + 4, center.getX() - w/2, center.getY());
	this->_drawBox(5, h + 4, center.getX() + w/2, center.getY());
	SDL_RenderPresent(_renderer);
}

void	Window::_drawPoint( RenderPoint point ) {

	RenderPoint	p;
	double		width;
	double		height;

	p = this->_RealPointToScaledPoint(point);
	width = p.bottomRight.getX() - p.topLeft.getX();
	height = p.bottomRight.getY() - p.topLeft.getY();
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	this->_drawBox(width, 3, p.topLeft.getX() + width/2, p.topLeft.getY());
	this->_drawBox(width, 3, p.topLeft.getX() + width/2, p.center.getY());
	this->_drawBox(width, 3, p.topLeft.getX() + width/2, p.bottomRight.getY());
	this->_drawBox(3, height, p.topLeft.getX(), p.topLeft.getY() + height/2);
	this->_drawBox(3, height, p.center.getX(), p.topLeft.getY() + height/2);
	this->_drawBox(3, height, p.bottomRight.getX(), p.topLeft.getY() + height/2);
	SDL_RenderPresent(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	this->_drawBox(5, 5, p.center.getX(), p.center.getY());
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
