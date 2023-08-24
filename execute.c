#include "monty.h"
/**
 *execute - Executes Monty bytecode commands
 * @stack: Pointer to the stack
 * @content: Command content to be executed
 * @counter: Line number of the command
 * @file: Pointer to the Monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
		command_t list[] = {
		{"push", push_node}, {"pall", t_pall}, {"pint", t_pint},
		{"pop", t_pop}, {"swap", t_swap}, {"add", t_add},
		{"nop", t_not}, {"pstr", t_pstr}, {"mod", t_mod},
		{"sub", t_sub}, {"stack", t_stack}, {"queue", t_queue},
		{"div", t_div}, {"mul", t_mult}, {"pchar", t_pchar},
		{"rotl", t_rotl}, {"rotr", t_rotr},
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
