#include <stdio.h>

#define MAX 300

float fah_to_cel(float f) { return (5.0 / 9.0) * (f - 32.0); }
float cel_to_fah(float c) { return c / (5.0 / 9.0) + 32.0; }

int main(void) {

  for (int i = 0; i < MAX; i++) {
    printf("Celcius: %3.3f -> Farenheight: %3.3f\n", (float)i,
           fah_to_cel((float)i));
  }
}
