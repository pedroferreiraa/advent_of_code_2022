#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	if (argc != 2) { return EXIT_FAILURE; }

	char *s = NULL;
	FILE *input = fopen(argv[1], "rb");
	int32_t sum, aux, calories, count, elf_number;
	size_t n = 0;

	sum = calories = count = elf_number = 0;

	while ((getline(&s, &n, input)) > 0) {
		aux = atoi(s);

		if (aux != 0) {
			sum += aux;
		} else {
			count++;
			if (sum > calories) {
				elf_number = count;
				calories = sum;
			}
			sum = 0;
		}

	}

	printf("Elf carrier is %d and carrying %d calories.\n", elf_number, calories);

	free(s);
	fclose(input);

	return 0;
}
