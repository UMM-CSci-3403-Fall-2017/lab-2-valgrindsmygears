#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char* argv[]) {
  char *line, *disemvoweled_line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);

  // Use a pointer to capture the output of disemvowel(line) 
  // so that we can free it after it's output.
  while (getline(&line, &size, stdin) > 0) {
    disemvoweled_line = disemvowel(line);
    printf("%s\n", disemvoweled_line);
    free(disemvoweled_line);
  }
  
  // Free the memory allocated to stdin.
  free(line);
}
