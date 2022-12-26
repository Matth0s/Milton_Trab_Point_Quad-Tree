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

static int	validatePoint( string point ) {

	string	x;
	string	y;

	if (point.find_first_of(",") == string::npos)
		return (1);
	x = point.substr(0, point.find_first_of(","));
	if (x.size() == 0 || x.find_first_not_of("0123456789") != string::npos)
		return (1);
	y = point.substr(point.find_first_of(",") + 1, point.size());
	if (y.size() == 0 || y.find_first_not_of("0123456789") != string::npos)
		return (1);
	return (0);
}

static int	validateFile( string* text ) {

	string	isSpaces = "\f\n\r\t\v";
	string	newText;
	string	substr;
	size_t	index;

	while (text->find_first_of(isSpaces) != string::npos) {
		index = text->find_first_of(isSpaces);
		text->replace(index, 1, string(" "));
	}

	while (text->find_first_not_of(" ") != string::npos) {
		*text = text->substr(text->find_first_not_of(" "), text->size());
		index = (text->find_first_of(" ") != string::npos)
				? text->find_first_of(" ") : text->size();
		substr = text->substr(0, index);
		if (validatePoint(substr))
			return (1);
		newText += substr + " ";
		*text = text->substr(index, text->size());
	}
	*text = newText;
	return (0);
}

static int	readFile( string fileName, string *text ) {

	std::ifstream		fileIn;
	std::stringstream	temp;

	fileIn.open( fileName.c_str(), ifstream::in );
	if (!fileIn.is_open())
		return (1);
	temp << fileIn.rdbuf();
	*text = temp.str();
	fileIn.close();
	return (0);
}

int			getPointsInput( int argc, char *argv[], string *points ) {

	if (argc != 1) {
		if (readFile(argv[1], points)) {
			cout << "Error in read file, exit code 1" << endl;
			return (1);
		}
		if (validateFile(points)) {
			cout << "Error in file syntax, exit code 1" << endl;
			return (2);
		}
	}
	return (0);
}