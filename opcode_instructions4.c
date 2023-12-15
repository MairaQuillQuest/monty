#include "monty.h"

/**
 * monty_rotl - rotates the first element to the bottom and  the second to the top
 *
 * @doubly_ll: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void monty_rotl(stacknode_t **doubly_ll, unsigned int nline)
{
	stacknode_t *aux1 = NULL;
	stacknode_t *aux2 = NULL;
	(void)nline;

	if (*doubly_ll == NULL)
		return;

	if ((*doubly_ll)->next == NULL)
		return;

	aux1 = (*doubly_ll)->next;
	aux2 = *doubly_ll;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly_ll;
	(*doubly_ll)->next = NULL;
	(*doubly_ll)->prev = aux2;
	*doubly_ll = aux1;
}

/**
 * monty_rotr - reverse the stack
 *
 * @doubly_ll: head of the linked list
 * @nline: line number
 * Return: no return
 */
void monty_rotr(stacknode_t **doubly_ll, unsigned int nline)
{
	stacknode_t *aux = NULL;
	(void)nline;

	if (*doubly_ll == NULL)
		return;

	if ((*doubly_ll)->next == NULL)
		return;

	aux = *doubly_ll;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly_ll;
	aux->prev = NULL;
	(*doubly_ll)->prev = aux;
	*doubly_ll = aux;
}
