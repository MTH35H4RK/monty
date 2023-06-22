#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *script_file = fopen(argv[1], "r");

	if (script_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	unsigned int line_number = 0;

	char *line = NULL;
	size_t line_size = 0;
	ssize_t line_length = 0;

	while ((line_length = getline(&line, &line_size, script_file)) != -1)
	{
		line_number++;

		char *opcode = strtok(line, " \t\n");
		char *argument = strtok(NULL, " \t\n");
