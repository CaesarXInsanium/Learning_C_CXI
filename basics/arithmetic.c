#include <math.h>
#include <limits.h> // used to import the hardware limitations of the integers.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#define PI 3.141592654
// used when one is not sure on real limits of the hardware.

int main() {
  u_int32_t uio;
  unsigned u;
  unsigned char uc;
  signed long long ull2; //signed is implicit and so can be ommited
  long long ull3;
  // wrapp around example
  u_int32_t n = 0;
  for (unsigned int i = n; i >= 0; --i){
    printf("Hello world! Num is : %u\n", i);
    // without this check code never ends.
    if (i == UINT_MAX){
      return EXIT_FAILURE;
    }
  }
  // this function determines if float is NaN, infinite, normal, subnormal or zero
  // refer to documentation for further information
  int answer = fpclassify(344.878);
  double ki = PI;

  // conversion example
  int conv =56;
  double cofv = (double)conv;
  // evil floating bit hack
  double num = 7.876;
  int *pointer = (int *)&num;
  // Implicit conversion

  unsigned int ui = UINT_MAX;
  signed char c = -1;
  if (c != ui){
    // this does not work on my machine as describe in the book Effective C
    puts("-1 equals 4,294,967,295");
  }
  return EXIT_SUCCESS;
}
