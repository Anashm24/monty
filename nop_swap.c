#include "monty.h"

/**
 * nop - Does nothing.
 * @element: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **element, unsigned int line_number)
{
	(void)element;
	(void)line_number;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @element: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **element, unsigned int line_number)
{
	stack_t *current;

	if (element == NULL || *element == NULL || (*element)->next == NULL)
		more_error(8, line_number, "swap");
	current = (*element)->next;
	(*element)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *element;
	current->next = *element;
	(*element)->prev = current;
	current->prev = NULL;
	*element = current;
}
