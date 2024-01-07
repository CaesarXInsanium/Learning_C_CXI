#include <stdio.h>

int main(void){
  float fahr, celcius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  while(fahr <= upper){
    // if arithmetic is peformed with int and float, then int it converted to int
    // and then result converted back to int implicitly
    celcius = (5.0/9.0) * (fahr - 32.0);
    // %3.0f tree characters and with no decimal part
    // %6.1f 6 chars plus 1 decimal char
    printf("%3.0f %6.1f\n", fahr, celcius);

    fahr = fahr + step;
  }
}
