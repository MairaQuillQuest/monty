#include "monty.h"
/**
 * _custom_calloc - concatenate two strings specially
 * @quelm: number of elements
 * @size: represents type of elements
 * Return: nothing
 */
void *_custom_calloc(unsigned int quelm, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (quelm == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(quelm * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (quelm * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * _custom_realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate memory. 
 * @old_size: old number of bytes
 * @new_size: new number of bytes
 * Return: nothing
 */
void *_custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
