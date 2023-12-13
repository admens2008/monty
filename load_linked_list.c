#include "monty.h"
char **load_linked_list(int line_number, char *_FILE);

/**
 * load_linked_list - load data from lines the second time
 * @line_number: line
 * @_FILE: file
 * Return: "tokens"
 */
char **load_linked_list(int line_number, char *_FILE)
{
	char buffer[60000];
	ssize_t bytesRead;
	char line[60000];
	static char *null[60000] = {NULL};
	int i, fileDescriptor, lineLength = 0;
	char **token;
	int j = 0;
	/*void (*f)(stack1_t **head, unsigned int line_number);*/
	/*stack1_t *head = NULL;*/

	/*    fileDescriptor = open(ALIAS_FILE, O_RDONLY);*/

	fileDescriptor = open(_FILE, O_RDONLY);
	if (fileDescriptor == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", info.filename);
		close(fileDescriptor);
		exit(EXIT_FAILURE);
		return (NULL);
	}

	j = 0;
	while ((bytesRead = read(fileDescriptor, buffer, 60000)) > 0)
	{
		for (i = 0; i < bytesRead; i++)
		{
			if (buffer[i] == '\n')
			{
				line[lineLength] = '\0';
				j++;
				token = (char **)tokenizer((char *)line);
				if (token != NULL)
				{
					if (line_number == j)
					{
						close(fileDescriptor);
						return (token);
					}
					else
					{
						/*error */
					}
				}
				/*_puts("\n");*/
				lineLength = 0;
			}
			else
			{
				line[lineLength] = buffer[i];
				lineLength++;
			}
		}
	}
	close(fileDescriptor);
	return (null);
}
