#include "monty.h"

/**
 * p_error - Outputs error messages corresponding to error codes.
 * @error_num: Error codes:
 * (1) => No/invalid input file(s).
 * (2) => Unreadable/open failure on provided file.
 * (3) => Invalid instruction in file.
 * (4) => Memory allocation failure (malloc).
 * (5) => Non-integer parameter for "push" instruction.
 * (6) => Empty stack for "pint" instruction.
 * (7) => Empty stack for "pop" instruction.
 * (8) => Short stack for operation.
 */
void p_error(int error_num, ...)
{
	va_list args;
	char *opt;
	int iNum;

	va_start(args, error_num);
	switch (error_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			iNum = va_arg(args, int);
			opt = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", iNum, opt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * p_more_error - Manages and reports errors.
 * @error_num: Error codes:
 * (6) => Empty stack encountered during 'pint'.
 * (7) => Empty stack encountered during 'pop'.
 * (8) => Insufficient elements in stack for operation.
 * (9) => Division by zero error.
 */
void p_more_error(int error_num, ...)
{
	va_list args;
	char *opt;
	int iNum;

	va_start(args, error_num);
	switch (error_num)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			iNum = va_arg(args, unsigned int);
			opt = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", iNum, opt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * p_str_error - Manages string-related errors.
 * @error_num: Error codes:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void p_str_error(int error_num, ...)
{
	va_list args;
	int iNum;

	va_start(args, error_num);
	iNum = va_arg(args, int);
	switch (error_num)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", iNum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", iNum);
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

