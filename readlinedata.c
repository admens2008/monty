#include "monty.h"
void *readlinedata(int ln, char *_FILE);
/**
 * readlinedata - ====
 * @ln: =====
 * @_FILE: ======
 * Description: =====
 * Return: POINTER OR null
 */
void *readlinedata(int ln, char *_FILE)
{
	char buffer[60000];
	ssize_t bytesRead;
	char line[60000];
	int i, fileDescriptor, lineLength = 0;
	unsigned int j = 0;
	char **token;
	void (*f)(stack1_t **head, unsigned int line_number);
	stack1_t *head = NULL;


	fileDescriptor = open(_FILE, O_RDONLY);
	info.fileDescriptor = fileDescriptor;
	if (fileDescriptor == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", info.filename);
		info.fileDescriptor = 0;
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
			if (token != NULL && token[0][0] != '#')
			{
			if (check_opcode(token) == 0 && check_opcode_arg(token) == 0)
			{
			if (ln == 0)
			{
				f = select_opcode(token);
				if (f != NULL)
				{
					close(fileDescriptor);
					f(&head, j);
				}
			}
			}
		else
		{
			if (info.err_no == -1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", j);
			}
			else if (info.err_no == -2)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						j, info.var._token[0]);
			}
			info.err_no = 0;
			info.fileDescriptor = 0;
			close(fileDescriptor);
			exit(EXIT_FAILURE);
		}
			}
			info.err_no = 0;
			info.var._token[0] = NULL;
			info.var._token[1] = NULL;
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
	info.fileDescriptor = 0;
	close(fileDescriptor);
	return (NULL);
}
