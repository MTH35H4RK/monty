#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;

		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}
