/*
** EPITECH PROJECT, 2018
** Projects
** File description:
** Main function for dante's project
*/

#include "generator.h"

int main(int argc, char **argv)
{
	maze_params_t *maze_params = malloc(sizeof(maze_params_t));
	srand(time(NULL));

	if (maze_params == NULL) {
		free(maze_params);
		exit(84);
	}
	if (argc > 4 || argc < 3 ||
	(argc == 4 && (strcmp(argv[3], "perfect") != 0))) {
		free(maze_params);
		exit(84);
	}
	check_args(maze_params, argv[1], argv[2]);
	generation(maze_params);
	if (argc != 4)
		not_perfect(maze_params);
	display(maze_params);
	free_maze(maze_params);
	return (0);
}

