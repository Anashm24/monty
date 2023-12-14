#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
} stack_t;

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

		void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void file_opening(char *filename);

int line_tokenizing(char *buffer, int line_number, int format);

void file_reading(FILE *);
int len_chars(FILE *);

/*function Handling*/
void run_command(char *, char *, int, int);

void excute_cmmnd(op_func func, char *op, char *val, int line_num, int format);

/*node handling*/
stack_t *create_new_node(int n);

void free_nodes(void);

/*Data structure*/
void add_to_stack(stack_t **, unsigned int);

void add_to_queue(stack_t **);

/*opcodes*/

void pall(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void pint(stack_t **, unsigned int);

void pop(stack_t **, unsigned int);

void nop(stack_t **, unsigned int);

void swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nodes(stack_t **, unsigned int);

void sub_nodes(stack_t **, unsigned int);


/*String operations*/
void print_char(stack_t **, unsigned int);

void print_str(stack_t **, unsigned int);

/*Error hanlding*/
void handle_error(int error_number, ...);

void more_error(int error_number, ...);

void str_error(int error_number, ...);

#endif
