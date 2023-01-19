#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int get_calories(char *name, int32_t *key)
{
	char *s = NULL;
	FILE *input = fopen(name, "rb");
	int32_t sum, aux, calories, count, elf_number;
	size_t n = 0;

	sum = calories = count = elf_number = 0;

	while ((getline(&s, &n, input)) > 0) {
		aux = atoi(s);

		if (aux != 0) {
			sum += aux;
		} else {
			count++;
			if (sum > calories && key[0] != sum && key[1] != sum && key[2] != sum) {
				elf_number = count;
				calories = sum;
			}
			sum = 0;
		}
	}

	printf("Elf carrier is %d and carrying %d calories.\n", elf_number, calories);
	free(s);
	fclose(input);

	return calories;
}

int main(int argc, char *argv[])
{
	if (argc != 2) { return EXIT_FAILURE; }

	int32_t i = 0, sum = 0;
	int32_t key[3] = {-1, -1, -1};

	for (i = 0; i < 3; ++i) {
		key[i] = get_calories(argv[1], key);
		sum += key[i];
	}

	printf("Sum: %d\n", sum);

	return 0;
}

