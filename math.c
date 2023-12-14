#include "monty.h"

/**
 * add_nodes - Adds the top two elements of the stack.
 * @element: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **element, unsigned int linenumber)
{
	int result;

	if (element == NULL || *element == NULL || (*element)->next == NULL)
		more_error(8, linenumber, "add");

	(*element) = (*element)->next;
	result = (*element)->n + (*element)->prev->n;
	(*element)->n = result;
	free((*element)->prev);
	(*element)->prev = NULL;
}

/**
 * sub_nodes - substract the top two elements of the stack.
 * @element: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **element, unsigned int linenumber)
{
	int result;

	if (element == NULL || *element == NULL || (*element)->next == NULL)

		more_error(8, linenumber, "sub");


	(*element) = (*element)->next;
	result = (*element)->n - (*element)->prev->n;
	(*element)->n = result;
	free((*element)->prev);
	(*element)->prev = NULL;
}
