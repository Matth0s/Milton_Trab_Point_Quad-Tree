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

#include "include.hpp"

void	testePoint( void ) {
	Point p(25, 25);

	cout << Point(1, 3) << "   "
		<< Point(3124, 5433) << "   "
		<< Point(43.431, 3543.435)<< "   "
		<< Point(1.4324, 323.23432) << endl;

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

void	testeTreeSearchWindow( void ) {

	Tree	QuadTree;

	QuadTree.insert(Point(80,45));

	QuadTree.insert(Point(40, 27.5));
	QuadTree.insert(Point(120, 27.5));
	QuadTree.insert(Point(120, 72.5));
	QuadTree.insert(Point(40, 72.5));

	cout << "Printa Todo Mundo " << endl;
	QuadTree.searchWindow(Point(0,0), Point(MAXX, MAXY));
	cout << endl;

	cout << "Primeiro Quadrante" << endl;
	QuadTree.searchWindow(Point(0,0), Point(80, 45));
	cout << endl;

	cout << "Segundo Quadrante" << endl;
	QuadTree.searchWindow(Point(80,0), Point(MAXX, 45));
	cout << endl;

	cout << "Terceiro Quadrante" << endl;
	QuadTree.searchWindow(Point(80,45), Point(MAXX, MAXY));
	cout << endl;

	cout << "Quanto Quadrante" << endl;
	QuadTree.searchWindow(Point(0,45), Point(80, MAXY));
	cout << endl;

	cout << "Norte" << endl;
	QuadTree.searchWindow(Point(0,0), Point(MAXX, 45));
	cout << endl;

	cout << "Leste" << endl;
	QuadTree.searchWindow(Point(80,0), Point(MAXX, MAXY));
	cout << endl;

	cout << "Sul" << endl;
	QuadTree.searchWindow(Point(0,45), Point(MAXX, MAXY));
	cout << endl;

	cout << "Oeste" << endl;
	QuadTree.searchWindow(Point(0,0), Point(80, MAXY));
	cout << endl;

}

void	testeTreeSearchDirection( void ) {

	Tree	QuadTree;

	QuadTree.insert(Point(80,45));

	QuadTree.insert(Point(40, 27.5));
	QuadTree.insert(Point(120, 27.5));
	QuadTree.insert(Point(120, 72.5));
	QuadTree.insert(Point(40, 72.5));


	cout << "Primeiro Quadrante" << endl;
	QuadTree.searchDirection(Point(80,45), "NW");
	cout << endl;

	cout << "Segundo Quadrante" << endl;
	QuadTree.searchDirection(Point(80,45), "NE");
	cout << endl;

	cout << "Terceiro Quadrante" << endl;
	QuadTree.searchDirection(Point(80,45), "SE");
	cout << endl;

	cout << "Quanto Quadrante" << endl;
	QuadTree.searchDirection(Point(80,45), "SW");
	cout << endl;

	cout << "Norte" << endl;
	QuadTree.searchDirection(Point(80,45), "N");
	cout << endl;

	cout << "Leste" << endl;
	QuadTree.searchDirection(Point(80,45), "E");
	cout << endl;

	cout << "Sul" << endl;
	QuadTree.searchDirection(Point(80,45), "S");
	cout << endl;

	cout << "Oeste" << endl;
	QuadTree.searchDirection(Point(80,45), "W");
	cout << endl;

}

void	drawBox( Sint32 x, Sint32 y, SDL_Surface* surface ) {

	SDL_Rect	box;

	box.w = 5;
	box.h = 5;
	box.x = x - box.w/2;
	box.y = y - box.h/2;

	SDL_FillRect(surface, &box, SDL_MapRGB(surface->format, 0, 0, 0));

}

void	testeDrawInWindow( void ) {

	SDL_Window*	window;
	SDL_Surface* surface;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "error: " << SDL_GetError() << endl;
		SDL_Quit();
	}
	window = SDL_CreateWindow("Quad-Tree",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAXX, MAXY, SDL_WINDOW_SHOWN);
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

int	main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;

	testePoint();
	testeTreeSearchWindow();
	testeTreeSearchDirection();
	testeDrawInWindow();

	return (0);
}
