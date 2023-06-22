#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being run
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        (void)line_number;

        while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
        {
                if (current->n == ' ')
                        break;

                printf("%c", current->n);
                current = current->next;
        }

        printf("\n");
}
