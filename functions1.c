#include "monty.h"

/**
 * stack_add - Pushes a node onto the stack.
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	head = *new_node;
	head->next = iTemp;
	iTemp->prev = head;
}

/**
 * print_s - Outputs elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void print_s(stack_t **stack, unsigned int line_number)
{
	stack_t *iTemp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	iTemp = *stack;
	while (iTemp != NULL)
	{
		printf("%d\n", iTemp->n);
		iTemp = iTemp->next;
	}
}

/**
 * top_pop - Pops the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void top_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *iTemp;

	if (stack == NULL || *stack == NULL)
		p_more_error(7, line_number);

	iTemp = *stack;
	*stack = iTemp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(iTemp);
}

/**
 * print_t - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_t(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		p_more_error(6, line_number);
	printf("%d\n", (*stack)->n);
}

