#include "monty.h"
void div_handler(stack1_t **head, unsigned int line_number);
/**
 * div_handler - ====
 * @head: =======
 * @line_number: ======
 */
void div_handler(stack1_t **head, unsigned int line_number)
{
	stack1_t *first;
	stack1_t *second;
	int div;
	stack1_t *newNode;

	*head = info.head2;
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	div = second->n / first->n;
	/*Remove the two nodes at the top to give room for the DIV result*/
	*head = second->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(first);
	free(second);

	/* Create a new node wand store thr div result */
	newNode = (stack1_t *)malloc(sizeof(stack1_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = div;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*head != NULL)
	{
		newNode->next = *head;
		(*head)->prev = newNode;
	}
	info.head2 = newNode;
}
