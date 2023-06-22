#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	char *value_str;
	int value;

	/* Read the integer value from the next token */
	value_str = strtok(NULL, " \t\n");
	if (value_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert the string to an integer */
	value = atoi(value_str);

	/* Create a new stack node */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Update the previous node of the current top node, if it exists */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Set the new node as the new top of the stack */
	*stack = new_node;
}
