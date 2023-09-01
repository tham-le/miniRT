#include "../../inc/miniRT.h"

int parsing(int ac, char **av)
{
    char *buffer;
    int file_no;

    buffer = NULL;
    if(ac != 2)
        return(write(STDERR_FILENO, ERROR_NUM_ARGS, 42));
    file_no = open(av[1], O_WRONLY);
    if(file_no == -1)
        return(write(STDERR_FILENO, ERROR_FILE, 35));
    if(!read(file_no, buffer, sizeof(int)))
        return(write(STDERR_FILENO, ERR_READ_FILE, 35));
    return(0);
}