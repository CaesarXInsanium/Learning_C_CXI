# Input/Output

We will now begin the proccess of learning about I/O

- reading/writing to files
- standard in/out/error
- terminal escape sequences
- command line interface
- POSIX functions

## Standard I/O Streams

- `stream`: abstraction over communication pipe between terminals/hardware and programs
- `FILE`: standard abstraction over systems that represent streams of data. use standard library functions in order to deal with them
- many behaviours defined in the standard library specification arre only reliable is the underlying implementation is valid
- there are not directories in standard C, must use implementation in order to deal with this. 
- POSIX, Windows NT and BSD all provide different libraries and functions for dealing with I/O

### Stream Buffering

Buffering is act of storing data in memory from external source such as hard drive and network interface. 
This is done in order to increase troughput and allow more data to be passed overall.
Sometimes once a certain amount of data is passed to memmory, it can be 'flushed' which is
sending that data over to destination such as writing to file and sending bytes over network.

- `unbuffered`: data appears in destination as soon as it is available. normaly the CPU for processing
- `fully buffered`: fully filling a block in order to be send to destination as a whole in one operation
- `line buffered`: transmitting block of data as soon as a newline character is reached. otherwise waiting until the next newline is reached in order to transmit
- drivers are capable of maintaining their own buffers.

### Predefined Streams

by default there are 3 predefined text streams. Declared in stdio.h

```c
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
```

- stdout: fully buffered, associated with the data that is output to terminal. or that is printed in command line interface,
- stdin: fully buffered, when program takes control of terminal and user and arbitrarly enter text/data as the program defines it
- stderr: not fully buffered. 
- all of this are more like pipes that control the have determined direction an purpose of data. 

### Stream Orientation

- determines wether or not pipe supports narrow or wide character, true implementation of the encoding
- if characters are used, stream pernamently becomes char based
- if bytes are used, pipe can only pass bytes
- streams can be reset with reopening of files or using function `fwide()`. fwide will determine orientation of FILE stream

### Text and Binary Streams

Text streams contained data that is encoded in a determined locale that can be intepreted as usefull. Each line is terminated with carriage return or newline

binary streams do that same but with binary data that cannot be used in text editors. Heavily implementation defined

- text files that are created in UNIX enviroments sometimes appear as one big line in windows systems

## Opening and Creating Files

files are associated with streams. Use the standard library functions in order to work with FILES

- `fopen`: standard function to creating FILE objects for dealing with files
- using different file opening flags can result in different behaviours, all of it depends heavily on the implementation
- exclisive mode 'x' fails if the file exists or cannot be created. make sure to have some robust error handling system in production
- KEEP ONE POINTER TO FILE

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    // undefined behaviour
    FILE *my_stdout = *stdout; //BAD!!
    if(fputs("Hello World!\n", &my_stdout) == EOF){
        return EXIT_FAILURE;
    }else{
      return EXIT_SUCCESS;
    }

  }
```

### Posix `open` function

establishes connection between file desriptor and actual file.

```c
int open(const char *path, int oflag,...);
```

- `file descriptor`: non-negative integer value representing structure of file
- oflag are determine from constants existing in the header file and careful use of bitwise OR and AND with all of the appropiate flags
- allows for reading, writing and dealing with directories too.
- there exist several other functions for purposes of dealing with file descriptors

### Closing Files


```c
#include <stdio.h>
int fclose(FILE *stream); // C standard library function for closing FILE streams
#include <unistd.h> //location of POSIX close from file descriptor
int close(int fd);
```

- unwritten data in buffer is sent to be written, unread data is discarded
- it is possible for this functions to fail: network errors, hardware issues. Everything is based on the implementation
- fopen files must close with fclose
- POSIX open() files must be closed with close()

## Reading and Writing

These exist versions of different functions for reading and writing that allow for normal chars and wide chars.
Check documentation.

- `getc`: read character
- `getchar`: read from stdin
- `fgets`: reads line from stream
- `putc`: write character to stream
- `puts`: writes string to standard out
- `fputs`: writes string to stream
- `putchar`: writes character to STOUT
- `ungetc`: return char to stream
- `scanf`: read formatted input from stdin
- `fscanf`: read formatted input from stream
- `printf`: print formatted character output to *stdout*
- `fprintf` : print formatted character to stream
- `sprintf`: print character output to buffer
- `snprintf`: takes length arugment in order to print to print to buffer 

## Stream Flushing

Data that is destinate towards streams is genereally buffered. One must flush the buffer
in order to have the data reach the destination

```c
// function will flush and write to stream
// NULL will flush all streams
int fflush(FILE *stream);
```
## Setting Position in File

Files all keep position indicate in stream. Originally positioned at the start of a file.

- `ftell`: will report current position
- `fseek`: will set position
- position represented by a long int starting at position 0

## Removing and Renaming Files

```c
int remove(const char *filename); //delete file from pathname. found in posix
int rename(const char *old, const char *new); //rename file in C standard
int unlink(const char *path); //POSIX delete function
```

## Using Temporary Files

temp files are used in interporcess communication, storing information that does not fit into RAM.
Using C Standard library implementations for `tmpfile`, `tmpnam`, and `mkstemp` for POSIX

- can exist globally or in private user's home directory
  - /tmp globally
  - $XDG_RUNTIME_DIR which is generally /run/user/$uid for linux
- best practice to store private user data in dedicated directories in order to avoid security vulnerabilities
- use `mkstemp` POSIX function

## Reading Formatted Text Streams

fscanf function will read formatted input.

```c
int fscanf(FILE * restrict stream, const char * restrict format,...);
```

- reads from stream and uses denoted format in order to denote conversion protocols
- can save input into variables but requires correct types and formatting
- specifiers matches to the first thing that fits description
- implementation is heavily determined by format strings

example usage

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int status = EXIT_SUCCESS;
  FILE *in;

  struct Sigrecord {
    int signum;
    char signame[10];
    char sigdesc[100];
  } sigrec;

  if ((in = fopen("basics/signals.txt", "r")) == NULL) {
    fputs("Cannot open signals.txt file\n", stderr);
    return EXIT_FAILURE;
  }

  do {
    // conversion specifier determines what to try and convert values to, can fail
    // implementation is heavily determined by regex
    // specifiers matches to the first thing that fits description
    // testing is very important with usage such as this
    int n = fscanf(in, "%d%9s%*[\t]%99[^\n]", &sigrec.signum, sigrec.signame,
                   sigrec.sigdesc);
    if (n == 3) {
      printf("Signal\n number = %d\n name =  %s\n description = %s\n\n",
             sigrec.signum, sigrec.signame, sigrec.sigdesc);
    } else if (n != EOF) {
      fputs("Failed to match signum, signame sigrec.sigdesc\n", stderr);
      status = EXIT_FAILURE;
    break;
    }

    else {
      break;
    }
  } while (1);

  if (fclose(in) == EOF) {
    fputs("Failed to close file\n", stderr);
    status = EXIT_FAILURE;
  }
  return status;
}
```

## Reading from and Writing to Binary Streams

C standard library contains functions for dealing with binary files. Files that do not have character encoding

```c
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
```

Function will takes *nmemb* elements of size *size* bytes from array designated by *ptr* and copies over to stream.

- check page 166 for example on to use this function, i don't feel like copying it over
- check endianess of files that we are working with. this deals with ordering of individual bits from most to least significat
- some fields at beginning of file are metadata for rest of file occasionally
