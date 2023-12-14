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


typedef void (*opfunc)(stack_t **, unsigned int);
extern stack_t *head;

/* file functions */
void open_f(char *file);
void read_f(FILE *);
int line_p(char *iBuff, int iNum, int iFormat);
void func_find(char *, char *, int, int);
void func_call(opfunc, char *, char *, int, int);

/* Functions operations */
stack_t *create_n(int n);
void free_n(void);
void print_s(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue_add(stack_t **, unsigned int);

int len_chars(FILE *);

void print_t(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void nope(stack_t **, unsigned int);
void swap_n(stack_t **, unsigned int);

/* Nodes math operations */
void add_n(stack_t **, unsigned int);
void sub_n(stack_t **, unsigned int);
void div_n(stack_t **, unsigned int);
void mul_n(stack_t **, unsigned int);
void mod_n(stack_t **, unsigned int);

/* Prints operations */
void print_c(stack_t **, unsigned int);
void str_p(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);

/* Errors operations */
void p_error(int error_num, ...);
void p_more_error(int error_num, ...);
void p_str_error(int error_num, ...);
void rot_r(stack_t **, unsigned int);

/* ENDIF */
#endif

