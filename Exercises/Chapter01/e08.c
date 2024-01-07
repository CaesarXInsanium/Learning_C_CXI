#include <stdio.h>

int newlines = 0;
int blanks = 0;
int tabs = 0;

int main(void){
  int current_char = 0;
  while((current_char = getchar()) != EOF){
    switch (current_char){
    case '\n':
      newlines++;
      break;
    case ' ':
      blanks++;
      break;
    case '\t':
      tabs++;
      break;
    default:
      ;
    }
  }
}
