#include <game_of_life.h>

int first_generation(bool matrix[width][height]) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (rand() % 2 == 0)
				matrix[i][j] = true;
			else
				matrix[i][j] = false;
		}
	}
	return (0);
}

bool adjacencies_alive(bool matrix[width][height], int i, int j) {
	int counter = 0;

	if (matrix[UP][MIDDLE] && matrix[UP][MIDDLE] == true)
		counter++;
	if (matrix[UP][RIGHT] && matrix[UP][RIGHT] == true)
		counter++;
	if (matrix[CENTER][RIGHT] && matrix[CENTER][RIGHT] == true)
		counter++;
	if (matrix[DOWN][RIGHT] && matrix[DOWN][RIGHT] == true)
		counter++;
	if (matrix[DOWN][MIDDLE] && matrix[DOWN][MIDDLE] == true)
		counter++;
	if (matrix[DOWN][LEFT] && matrix[DOWN][LEFT] == true)
		counter++;
	if (matrix[CENTER][LEFT] && matrix[CENTER][LEFT] == true)
		counter++;
	if (matrix[UP][LEFT] && matrix[UP][LEFT] == true)
		counter++;

	if (counter < 2 || counter > 3)
		return (false);
	return (true);
}

bool adjacencies_dead(bool matrix[width][height], int i, int j) {
	int counter = 0;

	if (matrix[UP][MIDDLE] && matrix[UP][MIDDLE] == true)
		counter++;
	if (matrix[UP][RIGHT] && matrix[UP][RIGHT] == true)
		counter++;
	if (matrix[CENTER][RIGHT] && matrix[CENTER][RIGHT] == true)
		counter++;
	if (matrix[DOWN][RIGHT] && matrix[DOWN][RIGHT] == true)
		counter++;
	if (matrix[DOWN][MIDDLE] && matrix[DOWN][MIDDLE] == true)
		counter++;
	if (matrix[DOWN][LEFT] && matrix[DOWN][LEFT] == true)
		counter++;
	if (matrix[CENTER][LEFT] && matrix[CENTER][LEFT] == true)
		counter++;
	if (matrix[UP][LEFT] && matrix[UP][LEFT] == true)
		counter++;

	if (counter != 3)
		return (false);
	return (true);
}

int check_neighbors(bool matrix[width][height], bool n_matrix[width][height]) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix[i][j] == true) {
				if (adjacencies_alive(matrix, i, j) == true)
					n_matrix[i][j] = true;
				else
					n_matrix[i][j] = false;
			}
			else {
				if (adjacencies_dead(matrix, i, j) == true)
					n_matrix[i][j] = true;
				else
					n_matrix[i][j] = false;
			}
		}
	}
	return (0);
}

int print_state(bool matrix[width][height], char alive, char dead) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix[i][j] == true)
				write(1, &alive, 1);
			else
				write(1, &dead, 1);
		}
		printf("\n");
	}
	return (0);
}

int copy_matrix(bool matrix[width][height], bool n_matrix[width][height]) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = n_matrix[i][j];
		}
	}
	return (0);
}
