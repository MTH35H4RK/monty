#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *next;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    next = (*stack)->next;

    top->prev = next;
    top->next = next->next;
    next->prev = NULL;
    next->next = top;

    if (top->next != NULL)
        top->next->prev = top;

    *stack = next;
}
