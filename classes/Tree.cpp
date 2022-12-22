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

#include "Tree.hpp"

Tree::Tree( void ): _root(nullptr) {}

Tree::~Tree( void ) { //deletar recursivamente a arvore
}

void	Tree::_insert( Point p, Node** node ) {

(void) p;
(void) node;
	// if (_root) {
	// 	_root = new Node(p, Point(0, 0), Point(160, 90), nullptr);
	// } else {

	// }

}

void	Tree::insert( Point p ) {

	if (this->has(p))
		return ;
	if (!_root) {
		_root = new Node(p, Point(0, 0), Point(160, 90), nullptr);
	} 
	// else {
	// 	this->_insert(p, )
	// }

}

bool	Tree::_has( Point p, Node* node ) {

	string	direction;
	
	if (!node)
		return (false);

	direction =	node->_center.relativePosition(p);
	if (direction == "NW")
		return this->_has(p, node->_northWest);
	if (direction == "NE")
		return this->_has(p, node->_northEast);
	if (direction == "SW")
		return this->_has(p, node->_southWest);
	if (direction == "SE")
		return this->_has(p, node->_southEast);
	return (true);
}

bool	Tree::has( Point p ) {
	if (_root)
		return this->_has(p, _root);
	return (false);
}
