#include "monty.h"
/**
 * _div - Performs division by dividing the second highest element on the stack by the top element.
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void divide(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}
