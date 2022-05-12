# Debugging, Testing and Analysis

## Assertions

sometimes certain assertions must be made in order to complete code and runtime corectness. Assertions should be used in 
in the code tests. Assertions take in boolean values, or any expression that results in a boolean. defined in `assert.h`

- static assertions
  - evaluated at compile time
  - `static_assert` this is a macro
  - use do bounds checkings at compile time and make sure that everything fits
- runtime assertions
  - is macro that is run at run time and will crash program if during runtime the thing does not work
  - can also take boolean expression or thing that outputs 1 or 0

## Compiler Settings and Flags

compilers do not enable optimazation, security or debuggin by default, such options must be enabled by arguments.
There are different classess of flags that can be defined to the compiler

- analysis: allows for compiler to check for errors and bugs
- debugguing: include debug infromation, assertions, runtime intrumentation for debuggers to use
- testing: check status of certain objects and values of certain variables
- aceptance testing: final testing, edge cases, etc...

### GCC, Clang Flags

check pages 204 in book. I am going to list interesting ones

- '-g3' generates debugging information. implementation dependent
- '-Wall' recomened compiler warnings, not all
- '-Werror' turns warnings into errors
- '-pedantic' warnings for comformace to standard
- '-O': issues compiler optimization. increases compilation time but increases final executable peformace. different levels available
- '-std=c99' determines C standard to use. influences accepted syntax. can even use C dialects with gnu
- '-D_FORTIFY_SOURCE=2' overflow detection
- '-fpie -WI' address space layout randomnization. security feature used to prevent attackers from guessing address of certain functions or values

## Debugging

Novices use print statements in order to debug code. Real professionals use debuggers.
IDEs allow for easy debuggin but CLI elites use the command line.

- 'step into' allows progression of program up until the breakpoint
- 'step over' skips breakpoint in the execution of function
- 'step out' continue until current stack frame terminates. whole program is terminated
- make sure to read documentation of the things that you are cheking the behaviour of

## Unit Testing

testing behavior of functions and implementations against data, edge cases and fuzzing that shit. Small 
programs for the purpose of exervising code. Validating against valid and invalid data for errors.

- use unit testin framework is recomened. This is in order to be able to do some things.
- assertions are made in a way to denote crashes and assertion failures both conclude that a test has failed
- some unit testing frameworks work unsing macros

## Static Analysis

using program to analyse program, look for mistakes that compiler cannot catch. However correctness of software is computationally undecidable.

- compiler does limited static analysis depending on compiler flags. try to understand error deeply and rethink implementation before using type casts
- seperate static analyser would allow for deeper analysis for errors and potential mishaps and security vulnerabilities
- there are both free and commercial options available
- go shopping and comparing and maybe use more than one since they might different but useful capabilities

## Dynamic Analysis

processes of evaluating system/binary during execution. runtime analysis..

- add compile time flags in order to add extra intructions in order to make it easier to analyse
- very low false positive rate
- heavily depends on code coverage during runtime. code problems will not be found if a function is not executed

### Address Sanitizer

dynamic memory error detector for C/C++. Incoporated into GCC and Clang.  Good for finding several classes of errors

- use after free
- heap stack overflow
- use after return
- use after scope
- init order bugs
- memory leaks

```sh
# intrument code by adding proper compiler flags
gcc -g3 -fno-omit-frame-pointer -fsanitize=address $SRC -o $TARGET
```
