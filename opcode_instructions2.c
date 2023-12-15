#include "monty.h"

/**
 * monty_queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_queue(stacknode_t **doubly_ll, unsigned int nline)
{
	(void)doubly_ll;
	(void)nline;

	g_data.lifo = 0;
}

/**
 * monty_stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_stack(stacknode_t **doubly_ll, unsigned int nline)
{
	(void)doubly_ll;
	(void)nline;

	g_data.lifo = 1;
}

/**
 * monty_add - adds the top two elements of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_add(stacknode_t **doubly_ll, unsigned int nline)
{
	int m = 0;
	stacknode_t *aux = NULL;

	aux = *doubly_ll;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly_ll)->next;
	aux->n += (*doubly_ll)->n;
	monty_pop(doubly_ll, nline);
}

/**
 * monty_nop - doesn't do anything
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_nop(stacknode_t **doubly_ll, unsigned int nline)
{
	(void)doubly_ll;
	(void)nline;
}

/**
 * monty_sub - subtracts the top element to the second top element of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_sub(stacknode_t **doubly, unsigned int nline)
{
	int m = 0;
	stacknode_t *aux = NULL;

	aux = *doubly_ll;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly_ll)->next;
	aux->n -= (*doubly_ll)->n;
	monty_pop(doubly_ll, nline);
}
