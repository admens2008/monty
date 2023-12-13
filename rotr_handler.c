#include "monty.h"
/**
 * rotr_handler - =======
 * @head: ==========
 * @ln: ===========
 */
void rotr_handler(stack1_t **head, unsigned int ln)
{
	stack1_t *last;
	stack1_t *first;

	(void)ln;
	*head = info.head2;
	if (*head == NULL || (*head)->next == NULL)
	{
		;
	}
	else
	{
		first = last = *head;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*head = last;
		info.head2 = last;
	}
}
