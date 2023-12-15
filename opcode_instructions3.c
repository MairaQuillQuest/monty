#include "monty.h"

/**
 * monty_div - divides the second element by the top element of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_div(stacknode_t **doubly_ll, unsigned int nline)
{
	int m = 0;
	stacknode_t *aux = NULL;

	aux = *doubly_ll;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	if ((*doubly_ll)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly_ll)->next;
	aux->n /= (*doubly_ll)->n;
	monty_pop(doubly_ll, nline);
}

/**
 * monty_mul - multiplies the top element to the second top element of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_mul(stacknode_t **doubly_ll, unsigned int nline)
{
	int m = 0;
	stacknode_t *aux = NULL;

	aux = *doubly_ll;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly_ll)->next;
	aux->n *= (*doubly_ll)->n;
	monty_pop(doubly_ll, nline);
}

/**
 * monty_mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_mod(stacknode_t **doubly_ll, unsigned int nline)
{
	int m = 0;
	stacknode_t *aux = NULL;

	aux = *doubly_ll;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	if ((*doubly_ll)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly_ll)->next;
	aux->n %= (*doubly_ll)->n;
	monty_pop(doubly_ll, nline);
}
/**
 * monty_pchar - print the character value of the first element
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_pchar(stacknode_t **doubly_ll, unsigned int nline)
{
	if (doubly_ll == NULL || *doubly_ll == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}
	if ((*doubly_ll)->n < 0 || (*doubly_ll)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly_ll)->n);
}

/**
 * monty_pstr - prints the string of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_pstr(stacknode_t **doubly_ll, unsigned int nline)
{
	stacknode_t *aux;
	(void)nline;

	aux = *doubly_ll;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
