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

# include "include.hpp"

static void	testePoint( void ) {

	Point p(25, 25);
	cout << Point(1, 3) << "   "
		<< Point(3124, 5433) << "   "
		<< Point(43, 3543) << "   "
		<< Point(1, 323) << "   "
		<< Point("321, 23423") << "   "
		<< Point("435, 2432") << "   "
		<< Point("654342, 43234") << "   "
		<< Point("423234, 5432") << endl;
	cout << endl;
	cout << (p.relativePosition(Point(10, 10)) == "NW" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(30, 10)) == "NE" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(30, 30)) == "SE" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(10, 30)) == "SW" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(10, 25)) == "SW" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(30, 25)) == "SE" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(25, 10)) == "NE" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(25, 30)) == "SE" ? "OK": "ERRO" ) << "  ";
	cout << (p.relativePosition(Point(25, 25)) == "EQUAL" ? "OK": "ERRO" ) << endl << endl << endl;

}

static void	printRenderPoints( RenderPoint* points ) {

	int	count = 0;

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

static void	testeTreeSearchWindow( void ) {

	Tree	quadTree;

	quadTree.insert(Point(WIDTH/2,HEIGHT/2));
	quadTree.insert(Point(WIDTH/4, HEIGHT/4));
	quadTree.insert(Point(WIDTH/4 * 3,  HEIGHT/4));
	quadTree.insert(Point(WIDTH/4 * 3, HEIGHT/4 * 3));
	quadTree.insert(Point(WIDTH/4, HEIGHT/4 * 3));

	cout << "Printa Todo Mundo " << endl;
	printRenderPoints(quadTree.searchWindow(Point(0, 0), Point(WIDTH, HEIGHT)));
	cout << endl;
	cout << "Primeiro Quadrante" << endl;
	printRenderPoints(quadTree.searchWindow(Point(0, 0), Point(WIDTH/2, HEIGHT/2)));
	cout << endl;
	cout << "Segundo Quadrante" << endl;
	printRenderPoints(quadTree.searchWindow(Point(WIDTH/2, 0), Point(WIDTH, HEIGHT/2)));
	cout << endl;
	cout << "Terceiro Quadrante" << endl;
	printRenderPoints(quadTree.searchWindow(Point(WIDTH/2, HEIGHT/2), Point(WIDTH, HEIGHT)));
	cout << endl;
	cout << "Quanto Quadrante" << endl;
	printRenderPoints(quadTree.searchWindow(Point(0, HEIGHT/2), Point(WIDTH/2, HEIGHT)));
	cout << endl;
	cout << "Norte" << endl;
	printRenderPoints(quadTree.searchWindow(Point(0, 0), Point(WIDTH, HEIGHT/2)));
	cout << endl;
	cout << "Leste" << endl;
	printRenderPoints(quadTree.searchWindow(Point(WIDTH/2, 0), Point(WIDTH, HEIGHT)));
	cout << endl;
	cout << "Sul" << endl;
	printRenderPoints(quadTree.searchWindow(Point(0, HEIGHT/2), Point(WIDTH, HEIGHT)));
	cout << endl;
	cout << "Oeste" << endl;
	printRenderPoints(quadTree.searchWindow(Point(0, 0), Point(WIDTH/2, HEIGHT)));
	cout << endl;

}

static void	testeTreeSearchDirection( void ) {

	Tree	quadTree;
	quadTree.insert(Point(WIDTH/2,HEIGHT/2));
	quadTree.insert(Point(WIDTH/4, HEIGHT/4));
	quadTree.insert(Point(WIDTH/4 * 3,  HEIGHT/4));
	quadTree.insert(Point(WIDTH/4 * 3, HEIGHT/4 * 3));
	quadTree.insert(Point(WIDTH/4, HEIGHT/4 * 3));

	cout << "Primeiro Quadrante" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "NW"));
	cout << endl;
	cout << "Segundo Quadrante" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "NE"));
	cout << endl;
	cout << "Terceiro Quadrante" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "SE"));
	cout << endl;
	cout << "Quanto Quadrante" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "SW"));
	cout << endl;
	cout << "Norte" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "N"));
	cout << endl;
	cout << "Leste" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "E"));
	cout << endl;
	cout << "Sul" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "S"));
	cout << endl;
	cout << "Oeste" << endl;
	printRenderPoints(quadTree.searchDirection(Point(WIDTH/2, HEIGHT/2), "W"));
	cout << endl;

}

static void	drawBox( Sint32 x, Sint32 y, SDL_Surface* surface ) {

	SDL_Rect	box;

	box.w = 5;
	box.h = 5;
	box.x = x - box.w/2;
	box.y = y - box.h/2;

	SDL_FillRect(surface, &box, SDL_MapRGB(surface->format, 0, 0, 0));

}

static void	testeDrawInWindow( void ) {

	SDL_Window*	window;
	SDL_Surface* surface;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "error: " << SDL_GetError() << endl;
		SDL_Quit();
	}
	window = SDL_CreateWindow("Quad-Tree",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "error: " << SDL_GetError() << endl;
		SDL_Quit();
	}
	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
	SDL_UpdateWindowSurface(window);

	bool	quit = false;
	while (!quit) {
		SDL_Event	event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_MOUSEBUTTONDOWN:
					drawBox(event.button.x, event.button.y, surface);
					SDL_UpdateWindowSurface(window);
					break;
				case SDL_QUIT:
					quit = true;
					break;
				default:
					break;
			}
		}
	}

	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

static void	testeReadFile( int argc, char *argv[] ) {

	string	points;

	if (getPointsInput(argc, argv, &points))
		return ;
	cout << endl << "Points in file: " << "|" << points << "|" << endl;

}

static void	testeTreeByInputFile( int argc, char *argv[] ) {

	string	points;

	if (getPointsInput(argc, argv, &points))
		return ;

	Tree	quadTree(points);
	delete[] quadTree.searchWindow(Point(0, 0), Point(WIDTH, HEIGHT));
}

static void	testeWindow( void ) {

	Tree	quadTree;
	Window	window("teste", &quadTree);

	while (!window.isClosed())
		window.pollEvents();

}

static void	testeWindowFileInput( int argc, char *argv[] ) {

	string	points;

	if (getPointsInput(argc, argv, &points))
		return ;
	Tree	quadTree(points);
	Window	window("teste", &quadTree);

	while (!window.isClosed())
		window.pollEvents();

}

void	teste( int argc, char *argv[] ) {

	(void) argc;
	(void) argv;

	testePoint();
	testeTreeSearchWindow();
	testeTreeSearchDirection();
	testeDrawInWindow();
	testeReadFile(argc, argv);
	testeTreeByInputFile(argc, argv);
	testeWindow();
	testeWindowFileInput(argc, argv);
}
