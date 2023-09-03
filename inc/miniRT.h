#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "structs.h"

# define ERROR_NUM_ARGS "Parse error: Invalid number of arguments\n"
# define ERROR_FILE "Parse error: file cannot be opened\n"
# define ERR_READ_FILE "Parse error: cannot read the file\n"



int parsing(int ac, char **av);

#endif 