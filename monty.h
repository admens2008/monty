#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>


/**
 * struct token_t - =====
 * @_token:=====
 */
typedef struct token_t
{
	char *_token[60000];
} token_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack1_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack1_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct info_t -  All member data
 * @err_no: =====
 * @filename: ======
 * @mode:=====
 * @fileDescriptor: ===
 * @var: =====
 * @head2: ====
 */
typedef struct info_t
{
	int err_no;
	char *filename;
	char *mode;
	int fileDescriptor;
	token_t var;
	stack1_t *head2;

} info_t;
info_t info;

void *readlinedata(int ln, char *_FILE);
void reset_tokens(char **arg);
void exitHandler(void);
int check_opcode(char **tokens);
int check_opcode_arg(char **token);
int _atoi(char *s);
void free_list(stack1_t *head);
void pint_handler(stack1_t **stack, unsigned int line_number);
void push_handler(stack1_t **stack, unsigned int line_number);
void div_handler(stack1_t **stack, unsigned int line_number);
void mod_handler(stack1_t **stack, unsigned int line_number);
void mul_handler(stack1_t **stack, unsigned int line_number);
void queue_handler(stack1_t **stack, unsigned int line_number);
void stack_handler(stack1_t **stack, unsigned int line_number);
void pall_handler(stack1_t **stack, unsigned int line_number);
void addnodefront(stack1_t **head, const int n);
char **load_linked_list(int line_number, char *_FILE);
char **tokenizer(char *line);
stack1_t *addnodetoend(stack1_t **head, const int n);
void nop_handler(stack1_t **stack, unsigned int line_number);
void pchar_handler(stack1_t **stack, unsigned int line_number);
void pop_handler(stack1_t **stack, unsigned int line_number);
void pstr_handler(stack1_t **stack, unsigned int line_number);
void rotl_handler(stack1_t **stack, unsigned int line_number);
void rotr_handler(stack1_t **stack, unsigned int line_number);
void sub_handler(stack1_t **stack, unsigned int line_number);
void swap_handler(stack1_t **stack, unsigned int line_number);
void print_stack(const stack1_t **h, unsigned int ln);
void (*select_opcode(char *op_code[]))(stack1_t **s, unsigned int ln);
void add_handler(stack1_t **stack, unsigned int line_number);

#endif
