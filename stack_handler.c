#include "monty.h"
/**
 * stack_handler - function to handle a stack operation,
 * which sets the stack mode to "stack" mode.
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: line number of the script
 */

void stack_handler(stack1_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	info.mode = "stack";
}
