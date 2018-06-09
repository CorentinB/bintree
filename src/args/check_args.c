/*
** EPITECH PROJECT, 2018
** Projects
** File description:
** __DESCRIPTION__
*/

#include "generator.h"

maze_params_t *check_args(maze_params_t *maze_params, char *x, char *y)
{
	char *error = "Arguments x and y should be numbers.";

	for (unsigned long i = 0; i < strlen(x); i++) {
		if (!isdigit(x[i])) {
			fprintf(stderr, "%s\n", error);
			exit(84);
		}
	}
	maze_params->x = atoi(x);
	for (unsigned long i = 0; i < strlen(y); i++) {
		if (!isdigit(y[i])) {
			fprintf(stderr, "%s\n", error);
			exit(84);
		}
	}
	maze_params->y = atoi(y);
	check_x_y(maze_params);
	return (maze_params);
}

void check_x_y(maze_params_t *maze)
{
	if ((maze->x - maze->y) >= 2 && maze->x >= 9) {
		free(maze);
		exit(84);
	}
}
