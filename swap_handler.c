#include "monty.h"

/**
 * swap_handler - ====
 * @head: ===
 * @line_number: ===
 */
void swap_handler(stack1_t **head, unsigned int line_number)
{
	stack1_t *first;
	stack1_t *second;

	*head = info.head2;
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	info.head2 = second;
}
