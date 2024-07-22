_<h1>Custom Printf Fuction</h1>_

_This project implements a simplified version of the standard C library function printf using C programming language._ The function _printf supports formatting options for characters (%c), strings (%s), and the percent symbol (%%). If an unsupported format specifier is encountered, it prints the specifier itself._

 _<h2>Features:</h2>_
 
| _Specifiers_ | _Description_                 |
|--------------|------------------------------ |
| '%c'         | _Print a single character_    |
| '%s'         | _Print a string of characters_|
| '%%'         | _Print a percentage symbol_   |

- _<h4>Unsupported Format Specifiers:</h4>_
   - _Prints the specifier as is._
 
- _<h4>Additional Functionality:</h4>_
   - _Handles NULL strings by printing "(null)"._

_<h2>Files:</h2>_

- _**main.h:**_ _Header file containing function declarations and necessary includes._
- _**main.c**_ _Source file containing the implementation of **_printf** and auxiliary functions._
- _**README.md**_ _This file, providing an overview of the project and usage instructions._

_<h2>usage:</h2>_

- _<h4>Compilation:</h4>_
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
- _<h4>Example Usage:</h4>_
```
#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;
    char ch = 'A';
    char *str = "Hello, world!";

    len = _printf("Let's print a character: %c\n", ch);
    _printf("Let's print a string: %s\n", str);
    _printf("Let's print the percent symbol: %%\n");
    _printf("Number of characters printed: %d\n", len);
    return (0);
}
```
- _<h4>Expected Output:</h4>_
```
Let's print a character: A
Let's print a string: Hello, world!
Let's print the percent symbol: %
Number of characters printed: 47
```
_<h2>Function Details</h2>_
- ___printf(const char *format, ...)___
  - _Main function that mimics printf. Takes a format string (format) and variable arguments (...). Iterates through the format string, printing characters directly unless it encounters a %, in which case it handles the specified format._

- ___print_string(char *str, int *contador)___
  - _uxiliary function used by _printf to print strings. If str is NULL, it prints "(null)"._
  
- __print_default(const char *format, int *i, int *counter)___
   - _Handles the default case for unsupported format specifiers._
 - ___strlen(const char *s)___
   - _Calculates the length of the string 's'._
- ___putchar(char c)___
  - _Writes the character c to the standard output._
