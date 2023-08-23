#include "monty.h"

/**
 * t_queue - Change to queue behavior
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: Sets the flag to indicate queue behavior.
 */
void t_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	car.type = 1;
}

/**
 * add_queue - Add a node to the end of the queue
 * @head: Pointer to the head of the queue
 * @n: Value to be added to the new node
 *
 * Description: This function adds a new node with the specified value
 * to the end of the queue represented by the stack_t structure.
 */
void add_queue(stack_t **head, int n)
{
	stack_t *end_node, *ptr;

	end_node = malloc(sizeof(stack_t));
	ptr = *head;
	if (end_node == NULL)
	{
		printf("Error\n");
		exit(1);
	}

	end_node->n = n;
	end_node->next = NULL;

	if (ptr)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = end_node;
		end_node->prev = ptr;
	}
	else
	{
		*head = end_node;
		end_node->prev = NULL;
	}
}
