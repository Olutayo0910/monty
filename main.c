#include "monty.h"
car_t car = {NULL, NULL, NULL, 0};
/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t n_line = 1;
	unsigned int counter = 0;
	char *content;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	car.file = file;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (n_line > 0)
	{
		content = NULL;
		n_line = getline(&content, &size, file);
		car.content = content;
		counter++;

		if (n_line > 0)
		{
			execute(content, &stack, counter, file);
		}

		free(content);
	}
	free_node(stack);
	fclose(file);

	return (0);
}
