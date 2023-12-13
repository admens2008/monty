#include "monty.h"
/**
 * hasAlphabet - ======
 * @token: =========
 * Return: ========
 */
int hasAlphabet(char *token)
{
	int i;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '-' || token[i] == '+')
			continue;
		if (!isdigit(token[i]))
		{
			return (-1);
		}
	}
	return (0);
}
/**
 * check_opcode_arg - ========
 * @token: ========
 * Return: =====
 */
int check_opcode_arg(char **token)
{
	int i;
	char *otheropcode[] = {"pall", "pint", "pop", "swap",
		"add", "nop", "sub", "div", "mul",
		"mod", "pchar", "pstr", "rotl", "rotr", "stack", "queue"};

	(void)token;
	for (i = 0; i < 16; i++)
		if (strcmp(info.var._token[0], otheropcode[i]) == 0)
			return (0);

	if (info.var._token[1] == NULL)
	{
		info.err_no = -1;
		return (-1);
	}
	info.err_no = hasAlphabet(info.var._token[1]);
	if (info.err_no == -1)
		return (-1);

	return (0);
}
