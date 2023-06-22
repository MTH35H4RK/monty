#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    char *value_str;
    int value;

    if (line_number < 1 || stack == NULL)
        return;

    value_str = strtok(NULL, " \n\t");
    if (value_str == NULL || !is_number(value_str))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
