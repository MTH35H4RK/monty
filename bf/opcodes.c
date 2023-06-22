#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
        stack_t *top, *current;

        (void)line_number;
        if (*stack == NULL || (*stack)->next == NULL)
                return;

        top = *stack;
        current = *stack;

        while (current->next != NULL)
                current = current->next;

        current->next = top;
        top->prev = current;

        *stack = top->next;
        (*stack)->prev = NULL;

        top->next = NULL;
}

/* Add more opcode functions here */
