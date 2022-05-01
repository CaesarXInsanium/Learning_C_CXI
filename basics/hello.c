#include <stdio.h>
#include <stdlib.h>

// Dumd comment that does not matter.
int main() {
  // Some functions are capable of returning values
  if (puts("Hello World!") == EOF){
    return EXIT_FAILURE;
    // Code here should not have to execute
  }
  // Formats
  printf("%s\n", "Hello World!");

  //Declaration of Variables
  return EXIT_SUCCESS;
}
