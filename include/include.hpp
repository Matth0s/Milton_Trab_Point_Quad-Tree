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

#ifndef INCLUDE_HPP
# define INCLUDE_HPP

# include <fstream>
# include <sstream>

# include "Point.hpp"
# include "Node.hpp"
# include "Tree.hpp"

// # include <SDL2/SDL.h>
// # include <SDL2/SDL_image.h>
// # include <SDL2/SDL_timer.h>


//___________________________________TESTES_____________________________________
void	testePoint( void );
void	testeTreeSearchWindow( void );
void	testeTreeSearchDirection( void );
// void	drawBox( Sint32 x, Sint32 y, SDL_Surface* surface );
// void	testeDrawInWindow( void );
void	testeReadFile( int argc, char *argv[] );


//________________________________INPUT_HANDLER_________________________________
int		readFile( string fileName, string* text );
int		validateFile( string* text );

#endif
