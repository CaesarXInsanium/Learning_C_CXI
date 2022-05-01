# Chapter 3

## Integers

There a limit number range of numbers that can be represented by integers. that is the reason for some manyu different bugs in thise world.

- `Padding`: used in order to accomodate hardware quirks. adds redundant zeros at beginning and end of int in memory
- `Precision`: number of bits used to represent integer.
- `Wrap arround`: occurs whenever a integer reaches the limits that is can present. some implementations allow for then the value to go around and 'reset'. ie 255+1 = 0 since 11111111 wraps to 00000000
- `Overflow`: occurs when operation returns value that cannot be represented in resulting type
- `Macro`: code that outputs more code. used in meta programming where one finds repetitive code writting but with a pattern that can be programmed
- values can either be represented correctly or with some error.
- there are signed adn unsinged integers defined by C standard
- unsigned integers of size 2^(n-1)
- sometimes representation cannot be chosen using C standard, it is entirely dependent on the implementation.

## Signed Integers

- `Sign amd Magnitude`: high order bit represetn sign and everything else represents number
- is is good practice to write integers as hexidecimals when they are used to represent binary imformation

## Floating Point

- used to represent real numbers up to  certain degree of accuracy.
- uses scientific noation
- larger float have more precision but higher storage requirements.
- exponent is the number that 10 is raised to
- significand is used to represent the decimal, a 1 is implicit and the rest is what is stored
- properties of real numbers are not upheld such associativity and distributivity
- also used to represent NaN, positive/negative infinity and integers
- constants are also define in the standard headers

### Types

each type includes a 1 bit sign. some bits to represent exponent and the rest are significand

- `float`: 32 bits
- `double`: 64 bits
- `long double`: 128 bits

## Conversion

sometimes certain values are passed into functions that are imcompatible with the types. conversion is then neccesary

- `implicit conversion`: coercion occurs automatically. 
- conversion promotion: increase in accuracy
- conversion demotion: decrease in accuracy. usually in floats
- certain integers cannot be converted because they represet a number that is too large to be represented in smaller integer type
- `usual arithmetic conversion`: convert items in expression/equation to all be the same type, usually via promoting the lowest ranked members
- unsigned integers become signed and raised a rank
- try to peform arithmetic between same types in order to avoid accuracy and safety concerns
- integer to float conversion are usually easily done except in certain cases where some accuracy is lost
- floating point to integers conversion results loss of fractional parts
