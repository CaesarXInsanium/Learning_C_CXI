# Dynamically Allocated Memory

Stack memory differs from heap memory since stack memory is preallocated at the start of each function call
with all the memory hat is required for all the related variables. However heap memory is required when  dealing 
object that have memory requirements that cannot be known at compile time. there are 4 main types:
static, thread, automatic and allocated.

## Storage Duration

All objects occupy storage space. Different types of allocated memory serve different purposes and as such 
have different properties. Automatic storage object exist only for the duration of the block in which they exist in.

- autmatic: exist for entire block
- static: exist for entire duration of program
- allocated: lives from the time it is allocated to when it is deallocated

- `Memory Manager`: library that allows for easy management of the heap whic are large blocks of memory. 
Will Make requests to operating system for memory to work. they only deal with the memory that is handed to them
- `Fragmentation`: occurs when small holes in otherwise full memory is created from deallocation of smaller
objects that results in the inability to allocated large chunks of memory
- `Memory Leaks`: occur when allocated memory is not returned to memory manager, resulting in inability to provided more storage space


## Memory Management function

C standard library provides several memory mangement functions, *aligned_alloc*, *calloc*, and *realloc*

### ***malloc***

allocs space for object of specified size with indeterminate initial size. 

- no type is required until object is copid into storage. Once there is data, pointer becomes of type ob last object allocated to memory
- allocate directly into declaration of custom type. no need to pointer type casting
- never read from uninitialized memory, this is undefined behaviour
- 

### ***aligned_alloc***

allows specification of both the size of allocated memory and the alignment type. used in case where
hardware rules are strict. required for overrulling compiler choices

```c
void *aligned_allow(size_t alignment, size_t size);
```

### ***calloc***

allocates for arrays of different types. initializes storage with zero value integer types. is not
same as float zero or null pointers. modern implementations check to see it arguments are valid

```c
void *calloc(size_t nmemb, size_t size);
```

### ***realloc***

changes size of allocated memory space and resizes that space. used to both growth and shrink sizes
of arrays

functions by allocating new storage with malloc and copying contents over to new storage.
new storage is left uninitialized

There is function ins OpenBSD that allows reallocation of arrays that allows overflow checking in array size calculations.
Does not zero out memory data.

### ***free**

Takes pointer to first part of allocated memory and deallocates, freeing it

```c
void free(void *ptr);
```

- Nothing happens with void pointers.
- Calling free twice on a pointer however causes a double free.
- pointers to freed memory are dangling pointers. writing too dangling pouinters causes vulnerabilities
- set pointers to NULL after freeing them, attempting anything will result in a crash which would allow for easier time testing and debugging

## Memory States

- unallocated, uninitialized: initial state of heap. cannot be read
- allocated, uninitialized: memory chunks partitioned for some data. should not be read
- allocated, initialized: data is written to chunks and are suitable to be read and written to

## Flexible Array Members

allows for data structures to exist within c that can change in size in accordance with the use case.

## Other Dynamically Allocated Storage

Stack: last in first out data structure class. allocated in stack frame. all function calls create a stack frame from global program memory.

### ***alloca**

- allows for dynamic allocation of stack during runtime. all memory is released after the called of the function terminate. 
- not defined with POSIX or C Standard library

### Variable Length arrays

some implementations of C allow for dimensions of array to defined at runtime using variables and such

```c
void func(size_t size){
    int vla[size];
  }
```

data is allocated in stack and freed upon end of scope. problems arise when program is unable to allocate
enough RAM for data and program crashes and then the world ends

- always make sure to validate lenght of array before attempting to allocate it
- size_of operation will no longer be reliable
- VLAs can be used in function parameters

```int matrix_sum(size_t rows, size_t cols, int m[rows][cols]){
    int total = 0;
    for(size_t r = 0; r < rows;r++){
        for(size_t c =0; c < cols; c++){
            total += m[r][c];
          }
      }
    return total;
  }
```

## Debugging Allocated Storage Problems

- keep dynamic memory management as simple as possible, keeping it withim same module, same file. same abstractions
- use dynamic analysis tools

### Dmalloc

simple library meant to replace default implementations in order to check to see if there are problems

There is also a command line utility used with constant heap verification and checking

running code with flags allows for easy checking of things

```sh
gcc -DDMALLOC main.c -o bin -ldmalloc
```

will provide log file with which one can check state of heap at time intervals

[Here is the link](https://dmalloc.com)

### Safety Critical

usually heap memory is not dealt with at all and only stack memory is worked in. at a consequence, questions on wether or not there is enough memory is always on the agenda.
