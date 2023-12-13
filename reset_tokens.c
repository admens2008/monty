#include "monty.h"

/**
 * reset_tokens - =====
 * @arg: ====
 */
void reset_tokens(char **arg)
{
	int i = 0;

	while (i < 60000)
	{
		arg[i] = NULL;
		i++;
	}
}
