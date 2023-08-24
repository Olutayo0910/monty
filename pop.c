#include "monty.h"

/**
 * t_pop - Removes the top element of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function removes the top element of the stack.
 */
void t_pop(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = ptr->next;
	free(ptr);
}
