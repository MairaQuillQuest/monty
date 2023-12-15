#include "monty.h"

/**
 * get_opcode_func - selects the correct opcode to perform
 *
 * @opc: represents opcode passed
 *
 * Return: returns pointer to the function that executes the opcode
 */
void (*get_opcode_func(char *opc))(stacknode_t **stacknode, unsigned int line_number)
{
	opfunc_t instruct[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"queue", monty_queue},
		{"stack", monty_stack},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_custom_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
