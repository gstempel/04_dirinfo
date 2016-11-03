#ifndef DIR_H
#define DIR_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct dirent dir;

void dirInfo(DIR *file);


#endif 
