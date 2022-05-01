#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  puts("Hello World."); // expression-statements
  ;                     // Null statement, does nothing
  {                     // Compund statement
    bool f = false;
    int c, a;
    static int count = 0;
    c += a;
    int h = ++count;

    if (190 > 6) {
      puts("This is conditional Statement");
    } else if (8 < 90) {
      puts("Second Condition!");
    } else {
      puts("Final shit");
    }
  }

  // Switch Statement
  int marks = 78;
  // most powerful statement in C
  switch (marks / 10) {
  case 10:
  case 9:
    puts("Grade is: A");
    break;
  case 8:
    puts("Grade is: B");
    break;
  case 7:
    puts("Grade is: C");
    break;
  default:
    puts("Failure, sentenced to death");
  }
  // Iteration Statements
  int x = 11;
  while (x > 0) {
    printf("%d\n", x);
    --x;
  }

  do {
    puts("Doing something stupid.");
    ++x;
  } while (x < 13);

  for (int x = 0; x < 11; x++) {
    printf("%d\n", x);
  }

  // GOTO statement
  goto YourMom;
  puts("this is you");
YourMom:
  puts("We are here! >:-)");
  return EXIT_SUCCESS;
}
