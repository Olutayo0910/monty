#include "monty.h"

/**
 * push_node - Pushes a new node onto the stack or queue
 * @head: Pointer to the head of the stack/queue
 * @counter: Line number
 *
 * Description: This function parses the argument to push a new integer node
 * onto the stack or queue based on the 'car.type' flag.
 */
void push_node(stack_t **head, unsigned int counter)
{
	int n, j = 0;
	int flag = 0;

	if (car.arg != NULL)
	{
		if (car.arg[0] == '-')
			j++;
		for (; car.arg[j] != '\0'; j++)
		{
			if (car.arg[j] > 57 || car.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(car.file);
			free(car.content);
			free_node(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(car.file);
		free(car.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(car.arg);
	if (car.type == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
