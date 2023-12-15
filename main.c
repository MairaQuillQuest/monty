#include "monty.h"

/**
 * read_line_alternative - reads a line from the file using fgets
 * @lineptr: pointer to the buffer where the line is stored
 * @n: pointer to the size of the buffer
 * @stream: file stream
 * Return: number of bytes read, or -1 on failure
 */
ssize_t read_line_alternative(char **lineptr, size_t *n, FILE *stream) {
    ssize_t bytes_read;
    *lineptr = NULL;
    *n = 0;

    // Read a line using fgets
    bytes_read = getline(lineptr, n, stream);

    // Remove newline character if present
    if (bytes_read != -1 && (*lineptr)[bytes_read - 1] == '\n') {
        (*lineptr)[bytes_read - 1] = '\0';
        bytes_read--;
    }

    return bytes_read;
}

/**
 * main - Monty entry point.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[]) {
    void (*f)(stacknode_t **stacknode, unsigned int line_number);
    FILE *file_desc;
    size_t size = 256;
    ssize_t nlines = 0;
    char *lines[2] = {NULL, NULL};

    file_desc = check_input(argc, argv);
    start_g_data(file_desc);

    nlines = read_line_alternative(&g_data.input_buffer, &size, file_desc);

    while (nlines != -1) {
        lines[0] = _custom_strtok(g_data.input_buffer, " \t\n");
        if (lines[0] && lines[0][0] != '#') {
            f = get_opcode_func(lines[0]);
            if (!f) {
                fprintf(stderr, "L%u: ", g_data.cur_line);
                fprintf(stderr, "unknown instruction %s\n", lines[0]);
                free_g_data();
                exit(EXIT_FAILURE);
            }
            g_data.sec_param = _custom_strtok(NULL, " \t\n");
            f(&g_data.dll_head, g_data.cur_line);
        }
        nlines = read_line_alternative(&g_data.input_buffer, &size, file_desc);
        g_data.cur_line++;
    }

    free_g_data();

    return 0;
}
