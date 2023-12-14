#include "monty.h"

/**
 * run_command - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_number: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void run_command(char *opcode, char *value, int line_number, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			excute_cmmnd(func_list[i].f, opcode, value, line_number, format);
			flag = 0;
		}
	}
	if (flag == 1)

	handle_error(3, line_number, opcode);
}

/**
 * excute_cmmnd - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @value: string representing a numeric value.
 * @l_n: line number for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void excute_cmmnd(op_func func, char *opcode, char *value, int l_n, int format)
{
	stack_t *stackNode;
	int multiplier;
	int index;

	multiplier = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			multiplier = -1;
		}
		if (value == NULL)

		handle_error(5, l_n);
		for (index = 0; value[index] != '\0'; index++)
		{
			if (isdigit(value[index]) == 0)

			handle_error(5, l_n);
		}
		stackNode = create_new_node(atoi(value) * multiplier);
		if (format == 0)
			func(&stackNode, l_n);
		if (format == 1)
			add_to_queue(&stackNode);
	}
	else
		func(&head, l_n);
}
