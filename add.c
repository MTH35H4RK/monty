#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
        stack_t *top;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        top = *stack;
        *stack = (*stack)->next;
        (*stack)->n += top->n;
        (*stack)->prev = NULL;
        free(top);
}
