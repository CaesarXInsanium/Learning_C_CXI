#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t num;
  int data[10];
  char c[10];
  int i;
  double d;
} widget;

// generates array of structs of the same type
void *func(size_t array_size) {
  widget *p = (widget *)malloc(sizeof(widget) + sizeof(int) * array_size);
  if (p == NULL) {
    return NULL;
  } else {
    p->num = array_size;
    for (size_t i = 0; i < p->num; ++i) {
      p->data[i] = 27;
    }
    return p;
  }
}
void example_malloc(void) {
  widget *p = malloc(sizeof(widget));
  if (p == NULL) { // malloc returns null pointer when allocation fails
    printf("Space was not allocated\n");
  } else {
    // for every call to *alloc, there must be a call to free memory
    free(p);
    p = NULL;
  }
}

void uninit_mem(void) {
  char *str = (char *)malloc(16);
  if (str != NULL) {
    // copy first fifteenn bytes of char array into str allocated space
    strncpy(str, "1234567890abc", 15);
    str[15] = '\0'; // set last byte to null byte
    printf("str = %s.\n", str);
    free(str);
    str = NULL;
  };
}

int main() {
  example_malloc();

  void *k = malloc(sizeof(widget)); // pointers can of type void
  void *status = realloc(k, 1010);  // resize an allocated pointer
  free(k);
  k = NULL;

  // uninit_mem();

  // flexible array function
  func(1000);
}
