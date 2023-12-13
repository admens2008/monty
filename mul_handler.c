#include "monty.h"
void mul_handler(stack1_t **head, unsigned int line_number);
/**
 * mul_handler - =========
 * @head: ==========
 * @line_number: ========
 */
void mul_handler(stack1_t **head, unsigned int line_number)
{
	stack1_t *first;
	stack1_t *second;
	int mul;
	stack1_t *newNode;

	*head = info.head2;
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	first = *head;
	second = (*head)->next;
	mul = second->n * first->n;

	/*Remove the top two nodes */
	*head = second->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(first);
	free(second);

	/* Create a new node with the sum */
	/*newNode = createNode(sum);*/
	newNode = (stack1_t *)malloc(sizeof(stack1_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = mul;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*head != NULL)
	{
		newNode->next = *head;
		(*head)->prev = newNode;
	}
	/**head = newNode;*/
	info.head2 = newNode;
}
