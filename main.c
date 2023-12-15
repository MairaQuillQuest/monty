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
    char *line = NULL;

    file_desc = check_input(argc, argv);
    start_g_data(file_desc);

    while (getline(&line, &size, file_desc) != -1)
    {
        char *lines[2] = {NULL, NULL};
        lines[0] = _custom_strtok(line, " \t\n");
        
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
        
        g_data.cur_line++;
    }

    free(line);
    free_g_data();

    return (0);
}
