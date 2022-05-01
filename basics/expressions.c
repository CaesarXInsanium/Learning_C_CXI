#include <stdio.h>

int f(void){
  return 0;
}

// declaring function that accepts other function
void g(int (*func)(void)){
  if (func() != 0){
    printf("g failed\n");
  }
}

int main(){
  int a; // declare a
  a = 0; //initialize a
  a = 9 + 10; // can also be initialized with an expression
  int b = 1 + 2; //will be simplified down to 3, a single value
  puts("Hello World"); //calling a function with argument
  
  g(f);

  int e;
  int c = 0; 
  e = c++; // uses value c the increments
  e = --c; //decrements first then uses value
 
  // Complement
  short d = 255;
  short f = ~d;

  // Shift operators. premature optimization is root of all evil
  int g = 45;
  int h = g << 4; // take g and shift 4 bits left
  int i = h & g;  // AND
  int j = i ^ h; // XOR. use pow function in order to riase number by power
  int k = j | i; // OR

  // logical operations
  if (6 == 7 && 4 + 7 <= 3){
    if (5 / 1 >= 5 || !(0)){
      puts("Conditions are met.");
    }
  }

  // Cast
  int l = 90;
  double m  = (double)l - 1;

  // Conditional
  // checks if 6 is equal to 7, returns 8 if true, 9 if false
  int n = 6 == 7 ? 8 : 9;

  // Pointer Arithmetic
  puts("Pointer Arithmetic");
  int arr[100];
  int *arrp1 = &arr[40];
  int *arrp2 = arrp1 + 20;
  printf("%td\n", arrp2 - arrp1);

  return 0;
}

