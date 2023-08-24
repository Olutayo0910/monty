#include "monty.h"

/**
 * t_mult - Multiplies the second element with the top element
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function multiplies the second element by the top element
 * and replaces the second element with the result.
 */
void t_mult(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int len = 0, temp;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	temp = ptr->next->n * ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}

