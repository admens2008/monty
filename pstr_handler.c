#include "monty.h"

/**
 * pstr_handler - =======
 * @h: ====
 * @ln: ======
 */
void pstr_handler(stack1_t **h, unsigned int ln)
{
	const stack1_t *curr = info.head2;

	(void)h;
	(void)ln;
	while (curr)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		printf("%c", (char)curr->n);
		curr = curr->next;
	}
	printf("\n");
}
