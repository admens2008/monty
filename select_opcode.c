#include "monty.h"
/**
 * select_opcode - =======
 * @op_code: ======
 * Return: ====
 */
void (*select_opcode(char *op_code[]))(stack1_t **stack,
		unsigned int line_number)
{
	instruction_t opcode_funcs[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"mul", mul_handler},
		{"div", div_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler}};

	int keys = 17;

	int j;

	for (j = 0; j < keys; j++)
		if (strcmp(opcode_funcs[j].opcode, op_code[0]) == 0)
			return (opcode_funcs[j].f);

	return (NULL);
}
