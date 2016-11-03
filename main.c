#ifndef MAIN_C
#define MAIN_C

#include "dir.h"

int main() {
  DIR *p = opendir(".");
  dirInfo(p);

  return 0;
}

#endif
