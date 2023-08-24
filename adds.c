#include "monty.h"

/**
 * t_add - Adds the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function adds the values of the top two elements
 * replaces the second element with the sum, and removes the first element.
 */
void t_add(stack_t **head, unsigned int counter)
{
		stack_t *ptr;
		int len = 0, temp;
		(void)counter;

		ptr = *head;

		/* Count the number of elements in the stack */
		while (ptr)
		{
			ptr = ptr->next;
			len++;
		}

		/* Check if there are at least 2 elements for addition */
		if (len < 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n",
					counter);
			fclose(car.file);
			free(car.content);
			free_node(*head);
			exit(EXIT_FAILURE);
		}

		/* Perform addition and update the stack */
		ptr = *head;
		temp = ptr->n + ptr->next->n;
		ptr->next->n = temp;
		*head = ptr->next;
		free(ptr);
}
