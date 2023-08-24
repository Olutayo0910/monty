#include "monty.h"

/**
 * t_div - Divides the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function divides the second element of the stack
 * by the top element and replaces the second element with the result.
 */
void t_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	temp = ptr->next->n / ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}
