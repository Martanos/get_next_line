#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;
    // Ensure the program is called with exactly one argument (the file to read).
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    // Attempt to open the file specified by the command-line argument.
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    // Read and print each line until NULL is returned (indicating EOF or an error).
    while (1) {
        line = get_next_line(fd);
        if (line == NULL) {
            // When get_next_line returns NULL, it could either be EOF or an error.
            // Since get_next_line typically doesn't distinguish between EOF and an error directly,
            // you might need to use additional logic or checks depending on your implementation.
            // For simplicity, we'll assume NULL strictly means EOF here.
            printf("Reached EOF or encountered an error\n");
            break; // Exit the loop
        }

        printf("Line: [%s]\n", line); // Print the line inside brackets to visually confirm its end
        free(line); // Don't forget to free the memory to avoid leaks
    }
    // Close the file descriptor.
    if (close(fd) == -1)
    {
        perror("Error closing file");
        return (1);
    }

    return (0);
}
