#include "monty.h"

global_t g_data;

/**
 * free_g_data - frees the global variables
 *
 * Return: no return
 */
void free_g_data(void)
{
	free_dll(g_data.dll_head);
	free(g_data.input_buffer);
	fclose(g_data.file_desc);
}

/**
 * start_g_data - initializes the global variables
 *
 * @file_desc: file descriptor
 * Return: no return
 */
void start_g_data(FILE *file_desc)
{
	g_data.lifo = 1;
	g_data.cur_line = 1;
	g_data.sec_param = NULL;
	g_data.dll_head = NULL;
	g_data.file_desc = file_desc;
	g_data.input_buffer = NULL;
}

/**
 * check_input - checks if the file exists and if it's possible for the file to 
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *file_desc;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_desc = fopen(argv[1], "r");

	if (file_desc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file_desc);
}

/**
 * main - Monty entry point. 
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stacknode_t **stacknode, unsigned int line_number);
	FILE *file_desc;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	file_desc = check_input(argc, argv);
	start_g_data(file_desc);
	while (fgets(g_data.input_buffer, size, file_desc) != NULL) 
	{
		lines[0] = _custom_strtok(g_data.input_buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode_func(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", g_data.cur_line);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_g_data();
				exit(EXIT_FAILURE);
			}
			g_data.sec_param = _custom_strtok(NULL, " \t\n");
			f(&g_data.dll_head, g_data.cur_line);
		}
		nlines = getline(&g_data.input_buffer, &size, file_desc);
		g_data.cur_line++;
	}

	free_g_data();

	return (0);
}
