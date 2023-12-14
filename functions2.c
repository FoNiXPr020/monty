#include "monty.h"

/**
 * nope - Performs no operation.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_n - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap_n(stack_t **stack, unsigned int line_number)
{
	stack_t *iTemp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		p_more_error(8, line_number, "swap");

	iTemp = (*stack)->next;
	(*stack)->next = iTemp->next;

	if (iTemp->next != NULL)
		iTemp->next->prev = *stack;

	iTemp->next = *stack;
	(*stack)->prev = iTemp;

	iTemp->prev = NULL;
	*stack = iTemp;
}

/**
 * add_n - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_n(stack_t **stack, unsigned int line_number)
{
	int iSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		p_more_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	iSum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = iSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_n - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void sub_n(stack_t **stack, unsigned int line_number)
{
	int iSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		p_more_error(8, line_number, "sub");

	(*stack) = (*stack)->next;
	iSum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = iSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_n - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void div_n(stack_t **stack, unsigned int line_number)
{
	int iSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		p_more_error(8, line_number, "div");

	if ((*stack)->n == 0)
		p_more_error(9, line_number);

	(*stack) = (*stack)->next;
	iSum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = iSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

