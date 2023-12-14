#include "monty.h"

/**
 * pall - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: line number of  the opcode.
 */
void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *current;

	(void) linenumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void pop(stack_t **stack, unsigned int linenumber)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		more_error(7, linenumber);

	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}

/**
 * pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void pint(stack_t **stack, unsigned int linenumber)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, linenumber);
	printf("%d\n", (*stack)->n);
}
