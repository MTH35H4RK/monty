#include "monty.h"

/**
 * pall - Print all values in the stack
 * @stack: Double pointer to the stack
 * @line_number: Current line number
 *
 * Description: This function prints all the values in the stack, starting from
 * the top.
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * push - Push a value onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Current line number
 *
 * Description: This function pushes an integer value onto the stack.
 * It expects an integer value as the next token in the input.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new_node;

	char *value;

	value = strtok(NULL, " \n");

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(value);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
