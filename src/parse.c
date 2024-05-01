#include <game_of_life.h>

char **read_map(int fd) {
	char *line = get_next_line(fd);
	char *total = ft_strdup("");

	while (line) {
		total = ft_strjoin_ex(total, line, 3);
		line = get_next_line(fd);
	}
	char **pattern = ft_split(total, '\n');
	return (pattern);
}

char *parse_map(char **pattern) {
	char *states;

	for (int i = 0; pattern[i]; i++) {
		if (pattern[i][0] == '#')
			;
		else {
			if (pattern[i][0] == 'x') {
				states = pattern[i + 1];
			}
		}
	}
	return (states);
}

int parse_states(char **states, bool matrix[height][width]) {
	for (int i = 0; states[i]; i++) {
		for (int j = 0; states[i][j]; j++) {
			if (ft_isdigit(states[i][j])) {
				if (states[i][j + 1] == 'b') {
					for (int x = 0; x < states[i][j] - '0'; x++) {
						matrix[i][j + x] = false;
					}
				}
				else if (states[i][j + 1] == 'o') {
					for (int x = 0; x < states[i][j] - '0'; x++) {
						matrix[i][j + x] = true;
					}
				}
			}
			if (states[i][j] == 'b')
				matrix[i][j] = false;
			else if (states[i][j] == 'o')
				matrix[i][j] = true;
		}
	}
	return (0);
}
