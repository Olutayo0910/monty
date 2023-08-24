#include "monty.h"

/**
 * t_swap - Swaps the top two elements of the stack.
 * @head: Double pointer to the head of the stack
 * @counter: Line number
 *
 * Description: If the stack contains less than two elements,
 * it prints an error message and exits with EXIT_FAILURE.
 */
void t_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	(*head)->prev = temp;
	(*head)->next = temp->next;
	temp->prev = NULL;
	temp->next = *head;

	if ((*head)->next != NULL)
		(*head)->next->prev = *head;

	*head = temp;
}
