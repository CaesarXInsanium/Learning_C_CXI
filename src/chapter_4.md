# Expression and Operators

## Expressions

keywords and operations symbols that are used in order to make math

- `Declaration`: means to tell compiler that there is variable to keep track off and need space to store
- `Initialization`: write to specified memory for variable with valid data in correct format
- `Evaluation`: means to simplify expression down to single value
- `Side Effects`: changes to global state in execution enviroment. include writing to object, I/O assignment accesing volatile object

## Function Invocation

- `function designator`: expression that has function type and use to invoke function
- `Variadic functions`: functions that can accept any number of arguments
- functions can also be passwd to other functions

## Order of Operations

Correct order of operations: parenthesis, postfix increment/decrement,
function call, array subscripting, structure union access, struct access via pointer,
compound literal

**Check the C standard for full list**. You might really need it someday

## Order of Evaluation

- heavily determined by implementation, decided by compiler
- try not to have two functions call and change the global state without some sort of planning
- can also c all functions and store results in variables in correct order in order to not rely too much on implementation
- dealing with function calls is annoying specially since order is very implementation dependent

## Interleaving

- `interleaving`: means to stop execution at one part of a expression and start another and switch back and forth in accordance with implemnetation
- functions generally do not interleave
- `size_of` is an operator. It is a function. more of a keyword. will return size in bytes as determined by size_t and CHAR_BIT

## Arithmetic

- "-a" returns negative of a
- "+a" returns itself, if and only if a is numerical type
- C implements truncating division. division is carried out normally and fractional part is discarded


I can write a rust function

```rust
fn is_odd<T:Div>(n: T) -> bool{
    n % 2 != 0
  }
```

## Bitwise operators

Manipulation of bits of integer types with no regard for represented values

- `Complement`: returns bitwise complement, flip all the bits. be careful with what implementation you are using
- `Shift Operators`: shift bits left and right. vacated bits are filled with zeroes. right hand side int must be not negative and 
- `Bitwise OR`: do OR operations across bits 
- `Bitwise XOR`: do XOR operations across bits 
- `Bitwise AND`: do the same except with AND

## Logical Operators

- logical AND : &&
- logical OR : &&
- use inly for boolean logic
- operands can of any type
-  guranteed left to right operation

## Cast Operations

Allows for object of certain types to be transformed into items of different types

- be vary of casting pointers down since loss of data is inevitable

## Conditional Operator

Takes 3 operand. Returns result based on condition. one line if statement

## '_Alignof' Operator

returns integer donoting alignment requirement for  declared complete object type

## Relational Operators

- >= <= == != < > 
- comparing equality of two pointers determines wether or not they point to same object

## Compound Assignment

- += -= sum and difference
- \*= /= %= product quetioent and remainder
- <<= >>= bitwise left and right shift
- &= ^= |=, bitwise AND XOR Or


## Comma

used to determine order of operations. used to seperate arguments in function 
and seperate order in which functions are evaluated

## Pointer Arithmetic

Adding pointers and integers are possible. This is mainly done to calculate the location of 
things in memory if there is no direct pointer to it.
