#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Description: This function is the entry point of the program. It reads a
 * file specified as a command-line argument, processes each line in the file,
 * and executes the corresponding instructions.
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n$");
		if (opcode && opcode[0] != '#')
			exec_instruction(opcode, &stack, line_number);
	}

	free_stack(stack);
	fclose(file);
	if (line)
		free(line);
	return (EXIT_SUCCESS);
}
