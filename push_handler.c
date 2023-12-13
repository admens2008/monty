#include "monty.h"
/**
 * push_handler - =======
 * @stack: ===
 * @line_number: =====
 * Return: ===
 */
void push_handler(stack1_t **stack, unsigned int line_number)
{
	char **data = NULL;
	char *data_ = NULL;

	data = load_linked_list(line_number, info.filename);
	*stack = info.head2;

	(void)data;
	if (info.mensah[0] != '\0')
	{
		if (strcmp(info.mode, "stack") == 0)
		{
			if (info.mensah[0] != '\0')
				addnodefront(stack, atoi(info.mensah));
		}
		else if (strcmp(info.mode, "queue") == 0)
		{
			if (info.mensah[0] != '\0')
				addnodetoend(stack, atoi(info.mensah));
		}
		free(data_);
	}
}
