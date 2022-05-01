# Chapter 2

Objects, functions and types

## Objects

- thing that can hold value. region of data storage that can represent values and invoked by programmer
- variables have declared type, which tells prperties about it
- can have types

## Functions

## Pointers

- most deadly thing in all of C
- point to beginning of location in memory.
- correct syntax to take pointer of thing `&thing`
- dereference `*thing`
- `Call by referance`: to pass pointer of thing into function and have the function then do thing
- `Call by Value`: values of thing are copied over to the function stack and then they are worked with

## Scope

Scope determines continous region in which object, function and can be accessed and defined.

refers only to identifiers otherwise known as variable names

- inner scopes can only be completely surrounded by outerscopes

## Storage Duraction

- `static`: can only be started with constants and will value will remain the same the entirety of the program


## Alignment

- detemines space requirements for objects. word is a natural fixed size unit of data that can be handled by intruction set
- 64 bits
- generally follows power of 2 boundaries
  - think about arrays. if each item does not take a single byte, try 2 bytes. then try 4 bytes. then try 8 bytes and so on
- represented using `size_t`

```c
struct S{
    int i; double d; char c;
  }
int main(void){
    unsigned char bad_buff[size_of(struct S)];
    _Alignas(struct S) unsigned char good_buff[size_of(struct S)];

    struct S *bat_s_ptr = (struct S *)bad_buff;
    struct S *good_s_ptr = (struct S *)good_buffl
  }
```

## Object Types

[Examples](./types.c)

- `pointer`: each type has its own pointer type
- `void` 
- `bool`
  - #include <stdbool.h> \n bool flag true;
- `char`: single characters. Determined heavily by locale and implementation
  - `signed`: can be used to represent small integer values
  - `unsigned`: in
  - both are not compatible with char
- `arrays`[T]
  - char[67]
  - 
- function: is pointer to procedure location in memory

### Numberical

- Ints: can be determined by platform or specificallty requested by program
  - `signed char`: same number of bytes as char
  - `short`: 8bits
  - `int`: size determined by platform. 64 bits on my machine
  - `long int`: genreally 32 bits but determined by implementation
  - `long long int`: 64 bits
  - `signed int`: first bit determines sign of number, positive or negative
  - `unsgined int`: only positive numbers
  - `uint32_t`: this must be unsigned and 32 bits

- Enums: assigs names to integer values in enumerable set of constants
  - `enum`
  - can be determined manually or automaticallly starting with 0

## Functions

- types are determined from return and parameter types
- `parameter`: object that function takes in, usually in order to act upon it
- `return`: used to determin item that will be returned to call. must be same type as as determine in declaration of function


## Derived Types

- pointers
  - `&`: takes takes object and returns pointer to it
  - `*`: takes pointer and follows it to reach real object. can also be used to determine pointer types
- arrays
  - continous allocation of objects. allocated by linker.
  - identifiers are pointers to items in beginning of array.
  - muti-dimensional arrays are possible
- tydef
  - used to declare aliases

```c
typedef unsigned int uint32_t;
typedef signed_char schar_type, *schar_type, (*fp)(void)
// identifiers should not end with '_t'
```

## Structures

Contains sequentially allocated member objects. Follows allignment rules. can have mistmatche of different types

```c
struct Sigrecord{
  int signum;
  char signame[20];
  char sigdesc[100];
} sigline, *sigline_p;

// access members
sigline.signum = 5;
&sigline->signum=6; // change member from behind pointer
```

## Union

used to save memory and by different objects that have similar fields. Unions can be of any variation but only
one at a time. can be used in graph data structures

```c
  union { struct {
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
```

## Tags

generally with custom types, using them as arguments requires this
`int foo(struct Bar bar)`. In order to not have to type out the thing, we must alias it with a typedef

```c
typedef struct tnode{
    int count;
    struct tnode *left;
    struct tnode *right;
  } tnode;

typedef struct Node Node;
struct Node{
    int count;
    struct tnode *left;
    struct tnode *right;
  } Node;
```

## Type Qualifiers

These things change behavour of the variables at runtime

- `const`: immutable. cannot be changed. attempts to change these will result in runtime error
- `volatile`: used to model memory mapped I/O, ports and values that can change during runtime due to outside things
- `restrict`: used to denote situation in which there exits only a single pointer to object and nothing else points to it
- `extern`: define visibility of definition of variable. mostly is implicit but can be used when variables are define in header files
