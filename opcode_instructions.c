#include "monty.h"

/**
 * monty_push - pushes an element to the stack
 *
 * @doubly_ll: head of the doubly linked list
 * @nline: line number
 * Return: no return
 */
void monty_push(stacknode_t **doubly_ll, unsigned int nline)
{
	int n, j;

	if (!g_data.sec_param)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "usage: push integer\n");
		free_g_data();
		exit(EXIT_FAILURE);
	}

	for (j = 0; g_data.sec_param[j] != '\0'; j++)
	{
		if (!isdigit(g_data.sec_param[j]) && g_data.sec_param[j] != '-')
		{
			dprintf(2, "L%u: ", nline);
			dprintf(2, "usage: push integer\n");
			free_g_data();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(g_data.sec_param);

	if (g_data.lifo == 1)
		add_node_begin(doubly_ll, n);
	else
		add_node_end(doubly_ll, n);
}

/**
 * monty_pall - prints all values on the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line numbers
 * Return: no return
 */
void monty_pall(stacknode_t **doubly_ll, unsigned int nline)
{
	stacknode_t *aux;
	(void)nline;

	aux = *doubly_ll;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * monty_pint - prints the value at the top of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number
 * Return: no return
 */
void monty_pint(stacknode_t **doubly, unsigned int nline)
{
	(void)nline;

	if (*doubly_ll == NULL)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "can't pint, stack empty\n");
		free_g_data();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly_ll)->n);
}

/**
 * monty_pop - removes the top element of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number
 * Return: no return
 */
void monty_pop(stacknode_t **doubly_ll, unsigned int nline)
{
	stacknode_t *aux;

	if (doubly_ll == NULL || *doubly_ll == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}
	aux = *doubly_ll;
	*doubly_ll = (*doubly_ll)->next;
	free(aux);
}

/**
 * monty_swap - swaps the top two elements of the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number
 * Return: no return
 */
void monty_swap(stacknode_t **doubly_ll, unsigned int nline)
{
	int m = 0;
	stacknode_t *aux = NULL;

	aux = *doubly_ll;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nline);
		free_g_data();
		exit(EXIT_FAILURE);
	}

	aux = *doubly_ll;
	*doubly_ll = (*doubly_ll)->next;
	aux->next = (*doubly_ll)->next;
	aux->prev = *doubly_ll;
	(*doubly_ll)->next = aux;
	(*doubly_ll)->prev = NULL;
}
