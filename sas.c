#include "monty.h"
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
        int temp = 0;
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
}
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
}
