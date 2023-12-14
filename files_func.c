#include "monty.h"

/**
 * open_f - Opens a file.
 * @file: The file pathname.
 * Return: Void.
 */
void open_f(char *file)
{
	FILE *fld = fopen(file, "r");

	if (file == NULL || fld == NULL)
		p_error(2, file);

	read_f(fld);
	fclose(fld);
}


/**
 * read_f - Reads a file.
 * @fld: Pointer to file descriptor.
 * Return: Void.
 */
void read_f(FILE *fld)
{
	int iNum, format = 0;
	char *iBuff = NULL;
	size_t iLen = 0;

	for (iNum = 1; getline(&iBuff, &iLen, fld) != -1; iNum++)
	{
		format = line_p(iBuff, iNum, format);
	}
	free(iBuff);
}

/**
 * line_p - Separates each line into tokens to determine
 * which function to call.
 * @iBuff: Line from the file.
 * @iNum: Line number.
 * @iFormat: Storage format. If 0, nodes will be entered as a stack.
 *           If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is for a stack, 1 if for a queue.
 */
int line_p(char *iBuff, int iNum, int iFormat)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (iBuff == NULL)
		p_error(4);

	opcode = strtok(iBuff, delim);
	if (opcode == NULL)
		return (iFormat);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_find(opcode, value, iNum, iFormat);
	return (iFormat);
}

/**
 * func_find - Finds the appropriate function for the opcode.
 * @opcode: Opcode.
 * @iValue: Argument of the opcode.
 * @iFormat: Storage format. If 0, nodes will be entered as a stack.
 *           If 1, nodes will be entered as a queue.
 * @ln: Line number.
 * Return: Void.
 */
void func_find(char *opcode, char *iValue, int ln, int iFormat)
{
	int iNum;
	int iFlag;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", print_s},
		{"pint", print_t},
		{"pop", top_pop},
		{"nop", nope},
		{"swap", swap_n},
		{"add", add_n},
		{"sub", sub_n},
		{"div", div_n},
		{"mul", mul_n},
		{"mod", mod_n},
		{"pchar", print_c},
		{"pstr", str_p},
		{"rotl", rot_l},
		{"rotr", rot_r},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (iFlag = 1, iNum = 0; func_list[iNum].opcode != NULL; iNum++)
	{
		if (strcmp(opcode, func_list[iNum].opcode) == 0)
		{
			func_call(func_list[iNum].f, opcode, iValue, ln, iFormat);
			iFlag = 0;
		}
	}
	if (iFlag == 1)
		p_error(3, ln, opcode);
}

/**
 * func_call - Calls the required function.
 * @iFunc: Pointer to the function about to be called.
 * @iCode: String representing the opcode.
 * @iValue: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @iFormat: Format specifier. If 0, nodes will be entered as a stack.
 *           If 1, nodes will be entered as a queue.
 */
void func_call(opfunc iFunc, char *iCode, char *iValue, int ln, int iFormat)
{
	stack_t *iNode;
	int iFlag;
	int iNum;

	iFlag = 1;
	if (strcmp(iCode, "push") == 0)
	{
		if (iValue != NULL && iValue[0] == '-')
		{
			iValue = iValue + 1;
			iFlag = -1;
		}
		if (iValue == NULL)
			p_error(5, ln);
		for (iNum = 0; iValue[iNum] != '\0'; iNum++)
		{
			if (isdigit(iValue[iNum]) == 0)
				p_error(5, ln);
		}
		iNode = create_n(atoi(iValue) * iFlag);
		if (iFormat == 0)
			iFunc(&iNode, ln);
		if (iFormat == 1)
			queue_add(&iNode, ln);
	}
	else
		iFunc(&head, ln);
}

