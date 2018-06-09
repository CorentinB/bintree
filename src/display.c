/*
** EPITECH PROJECT, 2018
** dante
** File description:
** Display maze
*/

#include "generator.h"

void display(maze_params_t *maze)
{
	for (int i = 0; i < maze->y; i++) {
		for (int j = 0; j < maze->x; j++)
			print_case(maze, i, j);
		if (i != (maze->y - 1))
			printf("\n");
	}
}

void print_case(maze_params_t *maze, int i, int j)
{
	if (maze->maze[i][j] == 0)
		printf("X");
	else
		printf("*");
}

void free_maze(maze_params_t *maze)
{
	for (int i = 0; i <= maze->y; i++)
		free(maze->maze[i]);
	free(maze->maze);
	free(maze);
}
