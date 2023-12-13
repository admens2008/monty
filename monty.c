#include "monty.h"
/**
 * exitHandler - =======
 * Return : =======
 * Description: =================
 */
void exitHandler(void)
{
	if (info.head2 != NULL)
		free_list(info.head2);
	if (close(info.fileDescriptor) == -1)
		return;
}
/**
 * signal_handler - ----=
 * @signum: ======
 */
void signal_handler(int signum)
{
	(void)signum;
	if (info.head2 != NULL)
	{
		stack1_t *curr = info.head2;
		stack1_t *temp = NULL;

		while (curr)
		{
			temp = curr;
			curr = curr->next;
			free(temp);
		}
		info.head2 = NULL;
	}
	exit(EXIT_SUCCESS);

}

/**
 * main - =========
 * @argc: =======
 * @argv: =======
 * Return: 0====
 */

int main(int argc, char **argv)
{
	int i = 0;

	info.head2 = NULL;
	info.err_no = 0;
	signal(SIGINT, signal_handler);
	/*signal(SIGTSTP, signal_handler);*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (i < 60000)
	{
		info.var._token[i] = NULL;
		i++;
	}

	info.mode = "stack";
	info.filename = argv[1];
	atexit(exitHandler);
	readlinedata(0, info.filename);
	free_list(info.head2);
	return (0);
}
