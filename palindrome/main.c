#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char* argv[]) {
  // Declare an extra pointer, result, to store the value returned by palindrome.
  // This allows us to store the result before the call to printf (from which there is no way of freeing a pointer). 
  char *line, *result;
  int size;
  
  size = 100;
  line = (char*) calloc (size + 1, sizeof(char));

  // fgets reads a line from stdin (usually the keyboard)
  // and returns it in the buffer passed as the first argument
  // (line here). If there's no more input to read from, it
  // returns NULL.
  while (fgets(line, size, stdin) != NULL) {
    // This crazy line removes the '\n' at the end of the input line.
    // Without it, nothing will ever be a palindrome, unless it happens
    // to somehow start with a '\n'.
    line[strcspn(line, "\n")] = '\0';
    
    // Store the intermediate value before printf so that we can free it later (and reassign for every loop).
    result = palindrome(line);
    printf("Is the string <%s> a palindrome? %s\n", line, result);
    free(result);
  }

  free(line);
}
