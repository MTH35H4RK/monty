#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
        char *value_str;
        int value;
        stack_t *new_node;

        if (stack == NULL)
        {
                fprintf(stderr, "L%u: stack is NULL\n", line_number);
                exit(EXIT_FAILURE);
        }

        value_str = strtok(NULL, " \n");
        if (value_str == NULL)
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        value = atoi(value_str);

        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = value;
        new_node->prev = NULL;

        if (*stack == NULL)
        {
                new_node->next = NULL;
        }
        else
        {
                new_node->next = *stack;
                (*stack)->prev = new_node;
        }

        *stack = new_node;
}
