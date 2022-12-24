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

void	testePoint( void ) {

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

void	testeTreeSearchWindow( void ) {

	Tree	quadTree;

	quadTree.insert(Point(MAXX/2,MAXY/2), NULL);
	quadTree.insert(Point(MAXX/4, MAXY/4), NULL);
	quadTree.insert(Point(MAXX/4 * 3,  MAXY/4), NULL);
	quadTree.insert(Point(MAXX/4 * 3, MAXY/4 * 3), NULL);
	quadTree.insert(Point(MAXX/4, MAXY/4 * 3), NULL);
	cout << "Printa Todo Mundo " << endl;
	quadTree.searchWindow(Point(0, 0), Point(MAXX, MAXY));
	cout << endl;
	cout << "Primeiro Quadrante" << endl;
	quadTree.searchWindow(Point(0, 0), Point(MAXX/2, MAXY/2));
	cout << endl;
	cout << "Segundo Quadrante" << endl;
	quadTree.searchWindow(Point(MAXX/2, 0), Point(MAXX, MAXY/2));
	cout << endl;
	cout << "Terceiro Quadrante" << endl;
	quadTree.searchWindow(Point(MAXX/2, MAXY/2), Point(MAXX, MAXY));
	cout << endl;
	cout << "Quanto Quadrante" << endl;
	quadTree.searchWindow(Point(0, MAXY/2), Point(MAXX/2, MAXY));
	cout << endl;
	cout << "Norte" << endl;
	quadTree.searchWindow(Point(0, 0), Point(MAXX, MAXY/2));
	cout << endl;
	cout << "Leste" << endl;
	quadTree.searchWindow(Point(MAXX/2, 0), Point(MAXX, MAXY));
	cout << endl;
	cout << "Sul" << endl;
	quadTree.searchWindow(Point(0, MAXY/2), Point(MAXX, MAXY));
	cout << endl;
	cout << "Oeste" << endl;
	quadTree.searchWindow(Point(0, 0), Point(MAXX/2, MAXY));
	cout << endl;

}

void	testeTreeSearchDirection( void ) {

	Tree	quadTree;
	quadTree.insert(Point(MAXX/2,MAXY/2), NULL);
	quadTree.insert(Point(MAXX/4, MAXY/4), NULL);
	quadTree.insert(Point(MAXX/4 * 3,  MAXY/4), NULL);
	quadTree.insert(Point(MAXX/4 * 3, MAXY/4 * 3), NULL);
	quadTree.insert(Point(MAXX/4, MAXY/4 * 3), NULL);

	cout << "Primeiro Quadrante" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "NW");
	cout << endl;
	cout << "Segundo Quadrante" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "NE");
	cout << endl;
	cout << "Terceiro Quadrante" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "SE");
	cout << endl;
	cout << "Quanto Quadrante" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "SW");
	cout << endl;
	cout << "Norte" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "N");
	cout << endl;
	cout << "Leste" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "E");
	cout << endl;
	cout << "Sul" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "S");
	cout << endl;
	cout << "Oeste" << endl;
	quadTree.searchDirection(Point(MAXX/2, MAXY/2), "W");
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

void	testeReadFile( int argc, char *argv[] ) {

	string	text;

	if (argc != 1) {
		if (readFile(argv[1], &text)) {
			cout << "Error in read file, exit code 1" << endl;
			return ;
		}
		if (validateFile(&text)) {
			cout << "Error in file syntax, exit code 1" << endl;
			return ;
		}
	}
	cout << "|" << text << "|" << endl;

}

void	testeTreeByInputFile( int argc, char *argv[] ) {

	string	text;

	if (argc != 1) {
		if (readFile(argv[1], &text)) {
			cout << "Error in read file, exit code 1" << endl;
			return ;
		}
		if (validateFile(&text)) {
			cout << "Error in file syntax, exit code 1" << endl;
			return ;
		}
	}

	Tree	quadTree(text);
	quadTree.searchWindow(Point(0, 0), Point(MAXX, MAXY));
}

void	testeGetRenderPoints( int argc, char *argv[] ) {

	string	text;

	if (argc != 1) {
		if (readFile(argv[1], &text)) {
			cout << "Error in read file, exit code 1" << endl;
			return ;
		}
		if (validateFile(&text)) {
			cout << "Error in file syntax, exit code 1" << endl;
			return ;
		}
	}

	Tree	quadTree(text);

	RenderPoint*	points = quadTree.getRenderPoints();
	int				size = quadTree.size();

	while (size--)
		cout << points[size].center << " | "
			<< points[size].topLeft << " | "
			<< points[size].bottomRight << endl;

	delete[] points;
}

void	testeWindow( void ) {

	Window	window("teste", MAXX, MAXY);

	while (!window.isClosed())
		window.pollEvents();

}