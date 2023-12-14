#include "monty.h"
/**
 * pop_handler - ====
 * @stack: =======
 * @line_number: ======
 */
void pop_handler(stack1_t **stack, unsigned int line_number)
{
	stack1_t *temp = info.head2;
	stack1_t *head = *stack;

	head = info.head2;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	head = head->next;
	if (head)
	{
		head->prev = NULL;
	}
	info.head2 = head;
	free(temp);
}
