#include "monty.h"

/**
 * check_opcode - ========
 * @tokens: ====
 * Return: ==
 */
int check_opcode(char **tokens)
{
	char *opcode[] = {"push", "pall", "pint", "pop",
		"swap", "add", "nop", "sub", "div", "mul", "mod",
		"pchar", "pstr", "rotl", "rotr", "stack", "queue"};
	int i;

	info.err_no = -2;
	(void)tokens;
	for (i = 0; i < 17; i++)
		if (strcmp(opcode[i], info.var._token[0]) == 0)
			return (0);
	return (info.err_no);

}
