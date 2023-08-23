#include "monty.h"

/**
 * t_stack - Set lifo behavior (stack mode)
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused)
 *
 * Description: This function sets the behavior of the program to LIFO mode
 * (stack mode) by updating the 'car.type' variable to 0.
 */
void t_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	car.type = 0;
}
