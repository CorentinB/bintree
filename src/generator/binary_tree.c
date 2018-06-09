/*
** EPITECH PROJECT, 2018
** dante
** File description:
** Performing binary tree
*/

#include "generator.h"

void perform(maze_params_t *maze, int pos_x, int pos_y)
{
	for (; pos_x < maze->y; pos_x += 2)
		perform_line(maze, pos_x, pos_y);
}

void perform_line(maze_params_t *maze, int pos_x, int pos_y)
{
	for (; pos_y < maze->x; pos_y += 2)
		take_decision(maze, pos_x, pos_y);
}

void take_decision(maze_params_t *maze, int pos_x, int pos_y)
{
	int random_number = (rand() % (1 - 0 + 1)) + 0;

	if (random_number == 0) {
		if (pos_x - 1 >= 0)
			dig_up(maze, pos_x, pos_y);
		else if (pos_y - 1 >= 0)
			dig_left(maze, pos_x, pos_y);
	} else {
		if (pos_y - 1 >= 0)
			dig_left(maze, pos_x, pos_y);
		else if (pos_x - 1 >= 0)
			dig_up(maze, pos_x, pos_y);
	}
}

void dig_up(maze_params_t *maze, int x, int y)
{
	maze->maze[x][y] = 2;
	maze->maze[x-1][y] = 2;
}

void dig_left(maze_params_t *maze, int x, int y)
{
	maze->maze[x][y] = 2;
	maze->maze[x][y-1] = 2;
}
