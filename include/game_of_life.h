#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

# include <libft.h>
# include <time.h>

# define UP i - 1
# define CENTER i
# define DOWN i + 1

# define LEFT j - 1
# define MIDDLE j
# define RIGHT j + 1

extern int width;
extern int height;

char **read_map(int fd);
char *parse_map(char **pattern);
int parse_states(char **states, bool matrix[height][width]);

int first_generation(bool matrix[width][height]);
bool adjacencies_alive(bool matrix[width][height], int i, int j);
bool adjacencies_dead(bool matrix[width][height], int i, int j);
int check_neighbors(bool matrix[width][height], bool n_matrix[width][height]);
int print_state(bool matrix[width][height], char alive, char dead);
int copy_matrix(bool matrix[width][height], bool n_matrix[width][height]);

#endif