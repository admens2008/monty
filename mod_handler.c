#include "monty.h"
void mod_handler(stack1_t **head, unsigned int line_number);

/**
 * mod_handler - =======
 * @head: ======
 * @line_number: =====
 */
void mod_handler(stack1_t **head, unsigned int line_number)
{
	stack1_t *first;
	stack1_t *second;
	int mod;
	stack1_t *newNode;

	*head = info.head2;
	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	first = *head;
	second = (*head)->next;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = second->n % first->n;
	/*Remove te nodes at the top to give room for the MOD result */
	*head = second->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(first);
	free(second);
	/* Create a new node where the mod will be stored */
	newNode = (stack1_t *)malloc(sizeof(stack1_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = mod;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (*head)
	{
		newNode->next = *head;
		(*head)->prev = newNode;
	}
	info.head2 = newNode;
}
