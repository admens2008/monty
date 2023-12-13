#include "monty.h"
/**
 * pchar_handler - =========
 * @head: ========
 * @line_number: =========
 */
void pchar_handler(stack1_t **head, unsigned int line_number)
{
	const stack1_t *curr = info.head2;

	(void)head;
	(void)line_number;
	if (curr == NULL || !curr || head == NULL || (*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
		if (curr->n > 127 || curr->n < 0)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", (char)curr->n);

		/*curr = curr->next;*/
		/*i++;*/
	/*free_stack(h);*/
}
