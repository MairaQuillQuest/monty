#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stacknode_s - doubly linked list for stack representation. 
 * @n: integer
 * @prev: Each node points to the previous element for efficient transversal. 
 * @next: Each node points to the next element for efficient operations. 
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct stacknode_s
{
	int n;
	struct stacknode_s *prev;
	struct stacknode_s *next;
} stacknode_t;

/**
 * struct globals - global structure to use in the stack or queue functions. 
 * @lifo: is stack or queue
 * @cur_line: current line
 * @sec_param: second parameter inside the current line
 * @dll_head: doubly linked list
 * @file_desc: file descriptor
 * @input_buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct globals
{
	int lifo;
	unsigned int cur_line;
	char  *sec_param;
	stacknode_t *dll_head;
	FILE *file_desc;
	char *input_buffer;
} global_t;

/**
 * struct OpFunc_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct OpFunc_s
{
	char *opcode;
	void (*f)(stacknode_t **stacknode, unsigned int line_number);
} OpFunc_t;

extern global_t g_data;

/* opcode_instructuions*/
void monty_push(stacknode_t **stacknode, unsigned int line_number);
void monty_pall(stacknode_t **stacknode, unsigned int line_number);
void monty_pint(stacknode_t **doubly_ll, unsigned int nline);
void monty_pop(stacknode_t **doubly_ll, unsigned int nline);
void monty_swap(stacknode_t **doubly_ll, unsigned int nline);
void monty_queue(stacknode_t **doubly_ll, unsigned int nline);
void monty_stack(stacknode_t **doubly_ll, unsigned int nline);
void monty_add(stacknode_t **doubly_ll, unsigned int nline);
void monty_nop(stacknode_t **doubly_ll, unsigned int nline);
void monty_sub(stacknode_t **doubly_ll, unsigned int nline);
void monty_div(stacknode_t **doubly_ll, unsigned int nline);
void monty_mul(stacknode_t **doubly_ll, unsigned int nline);
void monty_mod(stacknode_t **doubly_ll, unsigned int nline);
void monty_pchar(stacknode_t **doubly_ll, unsigned int nline);
void monty_pstr(stacknode_t **doubly_ll, unsigned int nline);
void monty_rotl(stacknode_t **doubly_ll, unsigned int nline);
void monty_rotr(stacknode_t **doubly_ll, unsigned int nline);

/*get function*/
void (*get_opcode_func(char *opc))(stacknode_t **stacknode, unsigned int line_number);

/*imported functions*/
int _sfch(char *s, char c);
char *_custom_strtok(char *s, char *d);
void *_custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_custom_calloc(unsigned int quelm, unsigned int size);
int _custom_strcmp(char *s1, char *s2);

/* doubly linked list functions */
stacknode_t *add_node_end(stacknode_t **dll_head, const int n);
stacknode_t *add_node_begin(stacknode_t **dll_head, const int n);
void free_dll(stacknode_t *dll_head);

/* main */
void free_g_data(void);

#endif
