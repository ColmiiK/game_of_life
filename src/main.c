#include <game_of_life.h>

int width = 100;
int height = 50;

int main(int ac, char **av) {
	int fd = 0;
	if (ac > 1 && ac < 3) {
		printf("Give me another parameter please.\n");
		return (1);
	}
	if (ac > 2) {
		width = atoi(av[1]);
		height = atoi(av[2]);
	}
	bool matrix[height][width];
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++){
			matrix[i][j] = false;
		}
	}
	if (ac == 4) {
		fd = open(av[3], O_RDONLY);
		if (!fd)
			return (1);
		char **pattern = read_map(fd);
		close(fd);
		char **states = ft_split(parse_map(pattern), '$');
		parse_states(states, matrix);
	}
	else {
		srand(time(NULL));
		first_generation(matrix);
	}
	while (true) {
		printf("\033[H");
		print_state(matrix, '#', ' ');
		bool n_matrix[height][width];
		check_neighbors(matrix, n_matrix);
		copy_matrix(matrix, n_matrix);
		usleep (50000);
	}
	return (0);
}