#ifndef SOLVE_H
# define SOLVE_H

#include <stdlib.h>

void	handle_maps(char **maps);
void	solve(char *map, char obstacle);
void 	set_obstacles_coordinates(int ***obstacles_coordinates, char *map,
		char obstacle);
int 	number_obstacles(char *map, char obstacle);

#endif
