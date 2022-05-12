# Preprocessor

part of C ompilation that happens before everything else. Basically just copies and pastes and generates one big source file in practice.

## The Compilation Process

- each phase in compilation proccess translate code for use in the next stages
- tokens are the smallest elements that is meaningful to compiler
- `preproccsor directives` are the means for controlling the bahaviour of the preprocessor before the translation into object code
- options can be bassed to compilers in order to output the post preproccesor result to see that MACROS are done correctly

```c
#include <stdio.h> //copies code that defines functions that are usefull
```

## File Inclusion

- header files declara variables and functions that are meant to defined/initialized in corresponding \*.c files
- header files are used for importing libraries and functions. 
- Preprocessor directives is a macro system that is used for changin certain text into other text
- resulting translation unit is one big translation unit
- quotes generally used to denote include path that is added in compiler flags

## Conditional Inclusion

- sometimes we want to include different functions based on implementation, platform and feature set that neccesitates needing to change the way and when some things get preprocessed
- preprocessor allows for conditional inclusion if appropiate directives. With such conditional it allows for metaprogramming and macros

```c
#if defined(_WIN32)
#include <Windows.h>
#elif defined(_ANDROID)
#include <android/log.h>
#endif
```

- check to see if certain macros exist and if so, include certain header files
- cannot use braces, only preprocessor directives using the pound symbols

### Generating Errors

sometimes if certain headers don't exist or certain conditions are not met, preprocessor allows for generation of compile time errors

```c
#if __STDC__ && __STDC_NO_THREADS__ != 1
#include <threads.h>
// code here ...
#elif POSIX_THREADS == 200809L
#include <pthread.h>
// code here ...
#else
int compile_error[-1]; // needs more descriptive error name
#error Neither <threads.h> nor <pthread.h> is available 
#endif
```

This code here checks to see if certain macros are defined in certain platforms and check to see which header to use.
If Neither header is available then code cannnot compile and will allow for compile time error

### Header Guards

You should add header guards in order to keep certain code from being repetead in the translation unit more than once.
This can lead to infinite recursion.

```c
#ifndef BAR_H
#define BAR_H
int func(void);
#endif
```

Write file specific name with extension. try to make sure to follow consistent convention in order to make sure that 
all header name are unique. Do not use reserve identifiers

`_FOO_H` is reserved identifier with leading underscore.

## Macro Definitions

macros can be defined with `define` directive. all of which are terminated with a newline

```c
#define BAR
#define ARRAY_SIZE 100
int array[ARRAY_SIZE];
#define FOO (1 + 1)
#define BAR(x) (x + (x))
#define STRINGIZE(x)

#define PASTE(X, Y) x ## _ ## y
int PASTE(foo,bar) = 12; //allows for token pasting and generating new identifiers
int foo_bar = 12;

// above will replace thing string

#define cbrt(X) _Generic((X), \
  long double: cbrt1(X), \
  default: cbrt (X), \
  float: cbrt(X) \
)
#undef BAR
```
- define BAR. all instances of BAR in code will be cut
- some macros replace all instance of a WORD with sometime else, generally sometime that is a pain to write down and 
- some macros take arguments and replace code with some other things. thse are function like macros
- sometimes certain macros can be defined in the compiler flags.
- you can also use multiline macros in order to get more metra programming done
- macros are inherintly dangerous since they replace all instances of a macro identifier with the definition
- it is possible to undefine macro with `#undef`
- it is neccesary to undefine macro in order to change definition
- remember MACRO inherintly work with strings and not source code tokens.

### Type Generic Macros

Sometimes if is possible to use macro to in order to use only one function on multiple different types in order
to use correct implementation of a operation on different data types

```c
#define sin(X) _Generic((X) \
  float: sinf, \
  double: sin, \
  long double: sin1 \
)(X)

// regardless od data type we are able to use correct implementation on each data type
int main(void){
    float f = sin(1.34234);
    double d = sin(3.121212);
  }
```

### Predefined Macros

Certain macros are already preblocked and forbidden from redifinition by user. these are already defined by the preprocessor.

- used to determining compilation enviroments
- host/target operating system
- header management
- implementation specific headers are also defined
- check page 182 for list of predefined headers or the C standard
