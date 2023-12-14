#include "monty.h"

/**
 * rotl_handler - ===
 * @head: ====
 * @ln: ==
 */
void rotl_handler(stack1_t **head, unsigned int ln)
{
	stack1_t *first;
	stack1_t *last;

	(void)ln;
	*head = info.head2;
	if ((!*head) || (*head)->next == NULL)
	{
		;
	}
	else
	{
		first = *head;
		last = *head;

		while (last->next)
			last = last->next;

		*head = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*head)->prev = NULL;
		info.head2 = *head;
	}
}
