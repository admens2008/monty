#include "monty.h"
/**
 * push_handler - function to push opcode
 * @stack: stack datastructure
 * @line_number: line number in file
 * Return: NULL is returned
 */
void push_handler(stack1_t **stack, unsigned int line_number)
{
	char **data = NULL;
	char *data_ = "120";

	data = load_linked_list(line_number, info.filename);
	*stack = info.head2;

	if (data != NULL && data[1] != NULL)
	{
		data_ = data[1];
	}
	if (data_ != NULL)
	{
		if (strcmp(info.mode, "stack") == 0)
		{
			if (data_ != NULL)
				addnodefront(stack, atoi(data_));
		}
		else if (strcmp(info.mode, "queue") == 0)
		{
			if (data_ != NULL)
				addnodetoend(stack, atoi(data_));
		}
	}
	/*	freedata(&data);*/
}
