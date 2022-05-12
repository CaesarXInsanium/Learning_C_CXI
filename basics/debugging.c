#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CxString {
  char **data;
  size_t size;
} CxString;

CxString *new (size_t size, char **data) {
  void *pointer = malloc(size);
  strncpy(pointer, *data, (unsigned long long)size);
  return (CxString *)pointer;
}

int main() {
  puts("Hello World!");
  // static assertion
  static_assert(
      1 == 1,
      "One does in fact equal to one"); // this be evaluated at compile time

  assert(9 == 9, "failure");
  return 0;
}
