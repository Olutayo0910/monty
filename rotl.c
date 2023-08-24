#include "monty.h"

/**
 * t_rotl - Rotates the stack to the top
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused)
 *
 * Description: This function rotates the stack to the top, moving the first
 * element to the last while maintaining the order of the other elements.
 */
void t_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp1 = *head, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp2 = (*head)->next;
	temp2->prev = NULL;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp1;
	(*head) = temp2;
}
