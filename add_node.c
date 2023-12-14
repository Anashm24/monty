#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *current;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	current = head;
	head = *new_node;
	head->next = current;
	current->prev = head;
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 */
void add_to_queue(stack_t **new_node)
{
	stack_t *current;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = *new_node;
	(*new_node)->prev = current;

}
