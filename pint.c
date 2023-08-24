#include "monty.h"

/**
 * t_pint - Prints the value at the top of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function prints the value at the top of the stack.
 * If the stack is empty, an error message is printed and the program exits.
 */
void t_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
