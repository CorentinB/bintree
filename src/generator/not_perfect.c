/*
** EPITECH PROJECT, 2018
** dante
** File description:
** Make a maze not perfect
*/

#include "generator.h"

void not_perfect(maze_params_t *maze)
{
	int random_x;
	int random_y;
	int to_break = (maze->x * maze->y) / 10;

	for (int i = 0; i <= to_break; i++) {
		random_x = rand() % maze->x;
		random_y = rand() % maze->y;
		if (maze->maze[random_x][random_y] == 0) {
			maze->maze[random_x][random_y] = 2;
		} else {
			i--;
		}
	}
}
