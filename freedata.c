#include "monty.h"

/**
 * freedata - ======
 * @arg: ===
 */
void freedata(char **arg)
{

	int i = 0;

	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
