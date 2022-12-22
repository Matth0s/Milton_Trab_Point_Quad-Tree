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

int	main(void) {

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

	cout << (p.relativePosition(Point(25, 25)) == "EQUAL" ? "OK": "ERRO" ) << endl; 
	return (0);
}
