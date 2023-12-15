#include "monty.h"

/**
 *add_node_end - add a note at the end of the doubly link list
 *@dll_head: first position of the doubly linked list
 *@n: data to be stored. 
 *Return: a doubly linked list
 */
stacknode_t *add_node_end(stacknode_t **dll_head, const int n)
{
	stacknode_t *tmpr, *aux;

	if (dll_head == NULL)
		return (NULL);
	tmpr = malloc(sizeof(stacknode_t));
	if (!tmpr)
	{
		dprintf(2, "Error: malloc failed\n");
		free_g_data();
		exit(EXIT_FAILURE);
	}
	tmpr->n = n;
	/*Careful with the first time*/
	if (*dll_head == NULL)
	{
		tmpr->next = *dll_head;
		tmpr->prev = NULL;
		*dll_head = tmpr;
		return (*dll_head);
	}
	aux = *dll_head;
	while (aux->next)
		aux = aux->next;
	tmpr->next = aux->next;
	tmpr->prev = aux;
	aux->next = tmpr;
	return (aux->next);
}

/**
 *add_node_begin - add a note at the begining of the doubly link list
 *@dll_head: first position of the doubly linked list
 *@n: data to be stored
 *Return: a doubly linked list
 */
stacknode_t *add_node_begin(stacknode_t **dll_head, const int n)
{
	stacknode_t *tmpr;

	if (dll_head == NULL)
		return (NULL);
	tmpr = malloc(sizeof(stacknode_t));
	if (!tmpr)
	{
		dprintf(2, "Error: malloc failed\n");
		free_g_data();
		exit(EXIT_FAILURE);
	}
	tmpr->n = n;
	/*Careful with the first time*/
	if (*dll_head == NULL)
	{
		tmpr->next = *dll_head;
		tmpr->prev = NULL;
		*dll_head = tmpr;
		return (*dll_head);
	}
	(*dll_head)->prev = tmpr;
	tmpr->next = (*head);
	tmpr->prev = NULL;
	*dll_head = tmpr;
	return (*dll_head);
}

/**
 * free_dll - frees the doubly linked list
 *
 * @dll_head: head of the doubly linked list
 * Return: no return
 */
void free_dll(stacknode_t *dll_head)
{
	stacknode_t *tmp;

	while ((tmp = dll_head) != NULL)
	{
		dll_head = dll_head->next;
		free(tmp);
	}
}
