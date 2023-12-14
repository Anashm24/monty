#include "monty.h"

/**
 * handle_error - Prints appropiate error messages determined.
 * @error_number: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void handle_error(int error_number, ...)
{
	va_list args;
	char *opcode;
	int line_number;

	va_start(args, error_number);
	switch (error_number)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_number = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @error_number: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void more_error(int error_number, ...)
{
	va_list args;
	char *opcode;
	int line_number;

	va_start(args, error_number);
	switch (error_number)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line_number = va_arg(args, unsigned int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
