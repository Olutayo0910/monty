#include "monty.h"

/**
 * t_rotr - Rotates the stack to the bottom
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused)
 *
 * Description: This function rotates the stack to the bottom, moving the last
 * element to the top while maintaining the order of the other elements.
 */
void t_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
