#include <stdio.h>

// Declaring function swap that is too be used
// Cannot be used without first defining that exeactly this function does.
// objects have lifetime. they live until the end of their scope
void swap(int a, int b){
  int k = a;
  a = b;
  b = k;
  printf("Main: a = %d, b = %d\n", a,b);
}

// takes pointers of two integers and swap the values at the pointers
// C is call by value, so values of things are copied over into the function stack. parameters are
// copied over. so in order to do function swap it need pointers
 void swap_p(int *pa, int *pb){
  int k = *pa;
  *pa = *pb;
  *pb = k;
}

int main(){
  int a = 21;
  int b = 9 + 10;

  swap(a,b);
  printf("Main: a = %d, b = %d\n", a,b);
  swap_p(&a, &b);
  printf("Main: a = %d, b = %d\n", a,b);
  
  //Possible to declare multiple variables
  char src, c;
  int x;
  int m;

  // declare array of size 90
  int p[90];
  src = 'l';
  c = 'k';
  x = 0;
  m = 8;

  int j; //scope of j begins
  // calling a function here would have any varaible named j overshadow the outerscope j.
  return 0;
}

