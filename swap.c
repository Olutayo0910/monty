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
	stack_t *top1, *top2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}

	top1 = *head;
	top2 = top1->next;

	top1->prev = top2;
	top1->next = top2->next;

	if (top2->next)
		top2->next->prev = top1;

	top2->next = top1;
	top2->prev = NULL;

	*head = top2;

	free(car.content);
}
