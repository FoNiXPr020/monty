#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: List of arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	open_f(argv[1]);
	free_n();
	
	return (0);
}

/**
 * create_n - Creates a node.
 * @n: Number to be stored inside the node.
 * Return: On success, a pointer to the created node. Otherwise, NULL.
 */
stack_t *create_n(int n)
{
	stack_t *iNode;

	iNode = malloc(sizeof(stack_t));
	
	if (iNode == NULL)
		p_error(4);
	
	iNode->next = NULL;
	iNode->prev = NULL;
	iNode->n = n;
	
	return (iNode);
}

/**
 * free_n - Frees all nodes in the stack.
 */
void free_n(void)
{
	stack_t *iTemp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		iTemp = head;
		head = head->next;
		free(iTemp);
	}
}

/**
 * queue_add - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number associated with the opcode.
 */

void queue_add(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *iTemp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	iTemp = head;
	while (iTemp->next != NULL)
		iTemp = iTemp->next;

	iTemp->next = *new_node;
	(*new_node)->prev = iTemp;

}

