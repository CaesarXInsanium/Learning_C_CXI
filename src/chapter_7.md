# Characters and Strings

formal definition of string is 

> A non empty set of characters, whose elements are members of an alphabet.  

## Characters

Characters are not native to the data that is present in bits and bytes. so several chracter encodings must be defined in order represent characters.
Certain integers values must be used in order to represent certain characters. most implementations are the same as the C implementation

- `ASCII`: 7 bit American Standard for information interchange, defines set of 128 characters. Some characters are reserved terminal control and others are normal writtable characters
  - developed in the US
- `unicode`: internationally recognized standard for encoding many different symbols and characters from a variaty of different languages. beginning of UTF range is ASCII
  - subdivided into planes, they each have similar sets of characters and are organized based on importance
  - UTF-8, UTD-16, UTF-32. UTF-8 is default on POSIX complient systems. UTF-16 in Windows NT systems
- `Locale`: define local conventions of language, nationality, culture and language
- `char`: is integer type that can represent ASCII characters. 
  - be careful to not mix signed and unsigned characters
- `wchar_t`: used to process character to large set. can be signed and unsigned. depends on implementation. can be used to represent any character in current system locale
- `char16_t`, `char32_t`: useless without libraries. these chars that are used in working with unicode characters

### Special Characters

- `Character literals`: sequences of characters encolsed in single qutes. used to denote special characters. very implementation defined
- `Escape Sequences`: used in terminals to represet certain actions, and to escape certain characters that are normaly have other uses.
  - `\n` `\t` `\\` 
  - generally backslash escapes symbols and uses latin characters to represent certain commands for terminal

### String Literalls

char arrays that are prefixed with certain terms in order to tell compiler facts about them. force certain implementations

- char: `"ABC"`
- wchar: `L"ABC"`
- utf: `u8"ABC"`
- char16: `u"ABC"`

### Linux and so does Windows

certain flags exist in GCC that allows for configuration of character sets.

### GNU ***libiconv***

open source library used for string conversion uses.


## String Handlers

- C Standard Library
  - string.h for narrow strings, wchar.h for wide strings
- strcpy, strncpy, strncat_s, copies bytes from source to destination
- memcpy
- strcpy - strinf copy
- strncpy - truncated zer filled copy
- memcpy - copies n number of code units
- strcat - concatenates strings
- strncat - truncation concatenates
- strcmp - string comparision
- strncmp - truncated
- strchr - locates char in string
- strcspn - computes length of complamentary string
- strpbrk - find first occurance of set of characters in string
- strrchr - firast occurance of char in string
- strspn - lenght of string segment
- strstr - find substring
- strok - string tokenizer
-  memchr - find code unit in memory
- compute string lenght
- memset - fill memory with code unit
- strlen - count number of characters until the termination byte is reached
- gets - function that accepts any amount of standard input with not way of actually allocating enough memory for it
- gets_s - better implementation that does array bounds checking for things that might fuck shit up



## Facts

- allows for passing of command line arguments for c program. the shell converts the CMD arguments into proper encoding for the program to use. gives a proper count and pointers
- when dealing with IO there is frequent switching between different character encodings and the way that they are used.
- there exist functions in C standard liobrary that allow for easy switching between character encodings
- careful because some casting/conversion can result in data and corruption if note done correctly
- C does not implement proper strings, only arrays of char




