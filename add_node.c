#include "monty.h"

/**
 * add_node - Add a node to the beginning of the stack
 * @head: Pointer to the head of the stack
 * @n: Value to be added to the new node
 *
 * Description: This function adds a new node with the specified value
 * to the beginning of the stack represented by the stack_t structure.
 */
void add_node(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *ptr = *head;

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	if (ptr != NULL)
	{
		ptr->prev = new_node;
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
