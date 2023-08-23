#include "monty.h"

/**
 * t_pall - Print all elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number counter
 */
void t_pall(stack_t **head, unsigned int counter)
{
	stack_t *ptr = *head;
	(void)counter;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
