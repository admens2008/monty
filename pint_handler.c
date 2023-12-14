#include "monty.h"

/**
 * pint_handler - ====
 * @stack: ======
 * @line_number: ====
 */
void pint_handler(stack1_t **stack, unsigned int line_number)
{
	const stack1_t *curr = info.head2;

	(void)stack;
	(void)line_number;
	if (!curr)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (curr)
	{
		printf("%d\n", curr->n);
		break;
	}
}
