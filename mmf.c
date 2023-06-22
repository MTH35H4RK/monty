#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
/**
 * free_stack - Free a stack
 * @stack: Pointer to the top of the stack
 *
 * Description: This function frees a stack by traversing through each node
 * starting from the top. It iteratively frees each node and moves to the next
 * until the entire stack is freed
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
