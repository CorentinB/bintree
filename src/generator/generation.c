/*
** EPITECH PROJECT, 2018
** dante
** File description:
** Generation
*/

#include "generator.h"

void generation(maze_params_t *maze)
{
	init_maze(maze);
	perform(maze, 0, 0);
	fill_last_right(maze);
}

void fill_last_right(maze_params_t *maze)
{
	if (maze->x % 2 == 0 && maze->y % 2 == 0) {
		maze->maze[maze->y - 1][maze->x - 1] = 2;
		maze->maze[maze->y - 1][maze->x - 2] = 2;
	} else {
		maze->maze[maze->y - 1][maze->x - 1] = 2;
	}
}

void init_maze(maze_params_t *maze)
{
	maze->maze = malloc(sizeof(int *) * (maze->y + 1));
	maze->maze[maze->y] = NULL;

	if (maze->maze == NULL) {
		free_maze(maze);
		exit(84);
	}
	for (int i = 0; i <= maze->y; i++) {
		maze->maze[i] = malloc(sizeof(int) * maze->x);
		if (maze->maze[i] == NULL) {
			free_maze(maze);
			exit(84);
		}
		if (i % 2 == 0) {
			init_maze_line(maze, i);
		} else {
			init_maze_free_line(maze, i);
		}
	}
}

void init_maze_line(maze_params_t *maze, int i)
{
	for (int j = 0; j < maze->x; j++) {
		if (j % 2 == 0) {
			maze->maze[i][j] = 1;
		} else {
			maze->maze[i][j] = 0;
		}
	}
}

void init_maze_free_line(maze_params_t *maze, int i)
{
	for (int j = 0; j < maze->x; j++)
		maze->maze[i][j] = 0;
}
