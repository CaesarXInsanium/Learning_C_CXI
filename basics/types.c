#include <stdio.h>
#include <stdlib.h>

int main() {
  char a = 'k';
  unsigned char b = 'l';
  char c[10];
  short d;
  unsigned short e;
  int f;
  unsigned int g;
  long int h;

  enum Day { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
  enum CardinalDirections { north = 0, east = 90, south = 180, west = 270 };
  struct Sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
  } sigline, *sigline_p;

  // access members
  sigline.signum = 5;
  int gh = 0;
  int *thing = malloc(sizeof(int));

  union {
    struct {
      int type;
    } n;
    struct {
      int type;
      int intnode;
    } ni;
    struct {
      int type;
      double doublenode;
    } nf;
  } u;
  u.nf.type = 1;
  u.nf.doublenode = 3.14;
  return EXIT_SUCCESS;
}

int f(void); // takes void and ouputs int
int *flip(); // returns pointer to int. can have any number of arguments passed.
void g(int i,
       int j); // named parameters. this is technically a function prototype.
