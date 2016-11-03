#ifndef DIR_C
#define DIR_C

#include "dir.h"


void dirInfo(DIR *file) {
  dir *d = readdir(file);

  if ( d == NULL )
    printf("\nERROR: %d - %s\n", errno, strerror(errno));

  else{
    printf("\nSTATS FOR DIRECTORY: %s\n", d->d_name);

    float size = 0;
    char *listOfDirs = malloc(sizeof(*listOfDirs));
    char *listOfFiles = malloc(sizeof(*listOfFiles));

    while(d) {//while directory stream is not null...

      if (d->d_type == DT_REG) {//if current file is a normal file, add to file array
	strcat(listOfFiles, d->d_name);
	strcat(listOfFiles, "\n");

      struct stat currFile;
      if ( stat(d->d_name, &currFile) < 0 )//stat getting run here
	printf("\nERROR: %d - %s\n", errno, strerror(errno));
      else
	size += currFile.st_size;
      }

      else {//if current file is a directory, add to dir array
	strcat(listOfDirs, d->d_name);
	strcat(listOfDirs, "\n");
      }

      d = readdir(file);
    }


  //convert size
  char s[4][4]= {
    " B",
    " KB",
    " MB",
    " GB",
  };
  int i = 0;//counter for unit of size
  while(size / 1024 > 1) {
    size = size/1024;
    i++;
  }

  printf("DIRECTORIES:\n%s", listOfDirs);
  printf("FILES:\n%s\n", listOfFiles);
  printf("Size of Directory: %f %s\n", size, s[i]);

  free(listOfDirs);
  free(listOfFiles);

  }
}

#endif
