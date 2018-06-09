/*
** EPITECH PROJECT, 2017
** generator.h
** File description:
** Contain all the prototypes needed for dante
*/

#ifndef GENERATOR_H
#define GENERATOR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct maze_params_s {
	int x;
	int y;
	int **maze;
} maze_params_t;
maze_params_t *check_args(maze_params_t *maze_params, char *x, char *y);
void generation(maze_params_t *maze);
void init_maze(maze_params_t *maze);
void init_maze_line(maze_params_t *maze, int i);
void display(maze_params_t *maze);
void init_maze_free_line(maze_params_t *maze, int i);
void print_case(maze_params_t *maze, int i, int j);
void perform(maze_params_t *maze, int pos_x, int pos_y);
void perform_line(maze_params_t *maze, int pos_x, int pos_y);
void take_decision(maze_params_t *maze, int pos_x, int pos_y);
void dig_up(maze_params_t *maze, int x, int y);
void dig_left(maze_params_t *maze, int x, int y);
void fill_last_right(maze_params_t *maze);
void free_maze(maze_params_t *maze);
void not_perfect(maze_params_t *maze);
void check_x_y(maze_params_t *maze);

#endif
