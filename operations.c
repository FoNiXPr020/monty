#include "monty.h"

/**
 * mul_n - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mul_n(stack_t **stack, unsigned int line_number)
{
	int iSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		p_more_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	iSum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = iSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_n - Computes the modulo of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */

void mod_n(stack_t **stack, unsigned int line_number)
{
	int iSum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		p_more_error(8, line_number, "mod");


	if ((*stack)->n == 0)
		p_more_error(9, line_number);

	(*stack) = (*stack)->next;
	iSum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = iSum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

