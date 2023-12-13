#include "monty.h"
/**
 * pint_handler - =======
 * @stack: =========
 * @line_number: ==========
 */

void pint_handler(stack1_t **stack, unsigned int line_number)
{
	const stack1_t *curr = info.head2;

	(void)stack;
	(void)line_number;
	/*printtopstack(&head, line_number);*/
	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		break;
		/*curr = curr->next;*/
		/*i++;*/
	}
	/*free_stack(h);*/
}
