#include "monty.h"

/**
 * f_sub - Subtracts the top element from the second top element of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function subtracts the top element from the second top
 * element of the stack and replaces the second top element with the result.
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int sub, node;

	temp = *head;
	for (node = 0; temp != NULL; node++)
		temp = temp->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
