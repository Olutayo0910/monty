#include "monty.h"

/**
 * t_pstr - Prints the string starting from the top of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function prints the string starting from the top
 * of the stack. It stops when a non-printable char or 0 is encountered.
 */
void t_pstr(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	(void) counter;

	ptr = *head;
	while (ptr)
	{
		if (ptr->n > 127 || ptr->n <= 0)
		{
			break;
		}
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}
