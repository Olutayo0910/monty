#include "monty.h"

/**
 * t_pchar - Prints the character at the top of the stack as ASCII
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function prints the character at the top of the stack as
 * an ASCII character.
 */
void t_pchar(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	(void)counter;

	ptr = *head;
	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ptr->n);
}
