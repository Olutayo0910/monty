#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack - doubly linked list representation of a stack
 * @n: integer value stored in the node
 * @prev: points to the previous element in the stack
 * @next: points to the next element in the stack
 *
 * Description: doubly linked list node structure for a stack
 */
typedef struct stack
{
	int n;
	struct stack *prev;
	struct stack *next;
} stack_t;

/**
 * struct car_s - information carrier -args, file, line content
 * @arg: arguement value
 * @file: pointer to monty file
 * @content: line content
 * @type: flag change type from stack to queue
 * Description: carries values through the program
 */
typedef struct car_s
{
	char *arg;
	FILE *file;
	char *content;
	int type;
}  car_t;
extern car_t car;

void add_node(stack_t **head, int n);
void free_node(stack_t *head);
void add_queue(stack_t **head, int n);
void t_queue(stack_t **head, unsigned int counter);
void t_stack(stack_t **head, unsigned int counter);
void push_node(stack_t **head, unsigned int counter);

#endif
