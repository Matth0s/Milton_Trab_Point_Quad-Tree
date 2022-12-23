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

int	main(int argc, char *argv[]) {

	string	text;

	if (argc != 1) {
		if (readFile(argv[1], &text)) {
			cout << "Error in read file, exit code 1" << endl;
			return (1);
		}
	}

	testePoint();
	testeTreeSearchWindow();
	testeTreeSearchDirection();
	// testeDrawInWindow();

	cout << endl;
	cout << text << endl;

	return (0);
}
