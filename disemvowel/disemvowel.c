#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "disemvowel.h"


/* Return the number of vowels in the given string.
 * Used to determine the amount of memory we need for the new character string (size - vowels + 1).
 */
int count_vowels(char* str) {
  const char* vowels = "AaEeIiOoUu";
  int vowel_count, old_string_length, i;
  
  old_string_length = strlen(str);
  vowel_count = 0;
  for (i=0; i<old_string_length; ++i) {
    // strchr checks for the first occurance of the character at str[i] in the constant char string 'vowels'. 
    // Returns a character pointer, or null if it is not found.
    if (strchr(vowels, str[i]) != '\0') {
      ++vowel_count;
    }
  }

  return vowel_count;
}

/* Return a new character string containing only the non-vowel elements of the given string.
 * count_vowels gets us the size of the new string.
 */
char* disemvowel(char* str) {
  const char* vowels = "AaEeIiOoUu";
  char* disemvoweled_string;
  int vowel_count, old_string_length, new_string_length, i, j;
  
  old_string_length = strlen(str);
  vowel_count = count_vowels(str);
  new_string_length = old_string_length - vowel_count;
  
  // j is used to walk through the indexes of the memory allocated for the new string
  // i walks through the entire old string.
  disemvoweled_string = (char*) calloc(new_string_length + 1, sizeof(char));
  j = 0;
  for (i=0; i<old_string_length; ++i) {
    // Add only non-vowel elements to the new string
    if (strchr(vowels, str[i]) == '\0') {
      disemvoweled_string[j] = str[i];
      ++j;
    }  
  }
  
  // Add the null terminator to the end of the new string 
  disemvoweled_string[j] = '\0';
  
  return (char*) disemvoweled_string;
}
