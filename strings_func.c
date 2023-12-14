#include "monty.h"

/**
 * print_c - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_c(stack_t **stack, unsigned int line_number)
{
	int iNum;

	if (stack == NULL || *stack == NULL)
		p_str_error(11, line_number);

	iNum = (*stack)->n;

	if (iNum < 0 || iNum > 127)
		p_str_error(10, line_number);

	printf("%c\n", iNum);
}

/**
 * str_p - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void str_p(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int iNum;
	stack_t *iTemp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	iTemp = *stack;
	while (iTemp != NULL)
	{
		iNum = iTemp->n;

		if (iNum <= 0 || iNum > 127)
			break;

		printf("%c", iNum);
		iTemp = iTemp->next;
	}

	printf("\n");
}

/**
 * rot_l - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot_l(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *iTemp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	iTemp = *stack;

	while (iTemp->next != NULL)
		iTemp = iTemp->next;

	iTemp->next = *stack;
	(*stack)->prev = iTemp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rot_r - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rot_r(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *iTemp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	iTemp = *stack;

	while (iTemp->next != NULL)
		iTemp = iTemp->next;

	iTemp->next = *stack;
	iTemp->prev->next = NULL;
	iTemp->prev = NULL;
	(*stack)->prev = iTemp;
	(*stack) = iTemp;
}

