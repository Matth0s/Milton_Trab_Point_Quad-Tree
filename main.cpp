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

void	teste1( void ) {
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

void	teste2( void ) {

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
	
	cout << "Lest" << endl;
	QuadTree.searchWindow(Point(80,0), Point(MAXX, MAXY));
	cout << endl;

	cout << "Sul" << endl;
	QuadTree.searchWindow(Point(0,45), Point(MAXX, MAXY));
	cout << endl;
	
	cout << "Oeste" << endl;
	QuadTree.searchWindow(Point(0,0), Point(80, MAXY));
	cout << endl;

}

int	main(void) {

	teste1();

	teste2();

	return (0);
}
