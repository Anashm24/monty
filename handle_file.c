#include "monty.h"

/**
 * file_opening - opens a file
 * @filename: the file namepath
 * Return: void
 */
void file_opening(char *filename)
{
	FILE *file_descriptor = fopen(filename, "r");

	if (filename == NULL || file_descriptor == NULL)
		handle_error(2, filename);

	file_reading(file_descriptor);
	fclose(file_descriptor);
}

/**
 * file_reading - reads a file
 * @file_descriptor: pointer to file descriptor
 * Return: void
 */
void file_reading(FILE *file_descriptor)
{
	int line_num, format = 0;
	char *buf = NULL;
	size_t buf_len = 0;

	for (line_num = 1; getline(&buf, &buf_len, file_descriptor) != -1; line_num++)
	{
		format = line_tokenizing(buf, line_num, format);
	}
	free(buf);
}



/**
 * line_tokenizing - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int line_tokenizing(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
		handle_error(4);

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	run_command(opcode, value, line_number, format);
	return (format);
}
