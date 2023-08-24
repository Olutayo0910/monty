#include "monty.h"

/**
 * free_node - frees a doubly linked list
 * @head: the first node
 */
void free_node(stack_t *head)
{
	stack_t *ptr;

	ptr = head;
	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
