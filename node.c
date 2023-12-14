#include "monty.h"

stack_t *head = NULL;
/**
 * create_new_node - Creates a node.
 * @data: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_new_node(int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = data;
	return (new_node);
}

/**
 * free_nodes - Frees nodes one by one in the stack.
 */
void free_nodes(void)
{
	stack_t *current;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
