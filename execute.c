#include "monty.h"

/**
 * execute - Execute a Monty bytecode command
 * @stack: Pointer to the stack
 * @content: Line content to parse
 * @counter: Line number
 * @file: Pointer to the Monty file
 *
 * Description: This function takes a line of Monty bytecode content,
 * parses the command opcode, and executes the corresponding function.
 * It matches the opcode with a list of available commands and their handlers.
 *
 * Return: 0 if successful, 1 if the command is not recognized
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	command_t list[] = {
		{"push", push_node},
		{"pall", t_pall},
		{"stack", t_stack},
		{"queue", t_queue},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	car.arg = strtok(NULL, " \n\t");
	while (list[i].opcode && op)
	{
		if (strcmp(op, list[i].opcode) == 0)
		{
			list[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_node(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
