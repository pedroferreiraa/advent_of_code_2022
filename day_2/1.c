#include <stdio.h>
#include <stdlib.h>

int play(int play_1, int play_2)
{
	int point = 0;

	if (play_1 == 'A') {
		switch (play_2) {
		case 'X':
			point = 1 + 3;
			break;
		case 'Y':
			point = 2 + 6;
			break;
		case 'Z':
			point = 3 + 0;
			break;
		}
	} else if (play_1 == 'B') {
		switch (play_2) {
		case 'X':
			point = 1 + 0;
			break;
		case 'Y':
			point = 2 + 3;
			break;
		case 'Z':
			point = 3 + 6;
			break;
		}
	} else {
		switch (play_2) {
		case 'X':
			point = 1 + 6;
			break;
		case 'Y':
			point = 2 + 0;
			break;
		case 'Z':
			point = 3 + 3;
			break;
		}
	}

	return point;
}

int main(int argc, char *argv[])
{
	if (argc != 2) { return EXIT_FAILURE; }

	FILE *fptr = fopen(argv[1], "rb");
	int ch, play_1, play_2, points;

	ch = play_1 = play_2 = points = 0;

	while (1) {
		if ((play_1 = fgetc(fptr)) == EOF) { break; }
		if ((ch = fgetc(fptr)) == EOF) { break; }
		if ((play_2 = fgetc(fptr)) == EOF) { break; }
		if ((ch = fgetc(fptr)) == EOF) { break; }

		points += play(play_1, play_2);

	}

	printf("Points is %d\n", points);
	fclose(fptr);

	return 0;
}
