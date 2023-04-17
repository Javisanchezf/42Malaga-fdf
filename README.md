<div id="header" align = center>
  <img src="https://github.com/Javisanchezf/media/blob/main/pc-gif.webp" width="200"/>
</div>

<h1 align = center>Libft by javisanchezf</h1>

> School 42 Málaga cursus project.

This repository contains all archives for the project __fdf__ in the __School 42 Málaga core cursus__.

<h2 align = center>
	<a href="#about">About</a>
	<span> · </span>
	<a href="#index">Index</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instuctions</a>
	<span> · </span>
	<a href="#testing">Testing</a>
	<span> · </span>
	<a href="#license">License</a>
</h2>

## About

This project is a __C library__ of useful functions that are allowed to be used in future __School 42 cursus__ projects. With access to this library, the coding proccess in incoming projects will be more effective. The aim of rewrite this functions is to get a better understanding of them, and get a whide range of utilities for the next projects. [You can find more information in the subject](https://github.com/Javisanchezf/42Malaga-pdfs/blob/main/libft_subject.pdf). As it's specified in the subjet, all the archives are in the same folder.

The code in this repository follows [the rules of the Norminette](https://github.com/Javisanchezf/42Malaga-pdfs/blob/master/norme.pdf).

## Index
### Functions from `<ctype.h>` library
* [`ft_isascii`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_isascii.c) : Test whether c is a 7-bit US-ASCII character code.
* [`ft_isalpha`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_isalpha.c) : Test a character to see if it's alphabetic.
* [`ft_isdigit`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_isdigit.c) : Test a character to see if it's a digit (0 through 9).
* [`ft_isalnum`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_isalnum.c) : Test a character to see if it's alphanumeric; it is equivalent to (isalpha(c) || isdigit(c)).
* [`ft_isprint`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_isprint.c) : Test a character to see if it's any printable character, including a space.
* [`ft_tolower`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_tolower.c) : Convert uppercase letters to lowercase.
* [`ft_toupper`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_toupper.c) : Convert lowercase letters to uppercase.

### Functions from `<stdlib.h>` library
* [`ft_atoi`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_atoi.c) : Convert the initial portion of the string pointed to by nptr to int.
* [`ft_calloc`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_calloc.c) : Allocate unused space for an array of "count" elements each of whose size in bytes is "size" and initializes to all bits 0.

### Functions from `<strings.h>` library
* [`ft_bzero`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_bzero.c) : Set the data in the n bytes of the memory starting at the location pointed to by s, to null bytes (filling it with zeroes).
* [`ft_memset`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_memset.c) : Set the first n bytes of the memory area pointed to by s with the constant byte c.
* [`ft_memchr`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_memchr.c) : Scans the initial n bytes of the memory area pointed to by s for the first instance of c.
* [`ft_memcmp`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_memcmp.c) : Compare the first n bytes of the memory areas s1 and s2.
* [`ft_memmove`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_memmove.c) : Copy n bytes from memory area src to memory area dest, handling overlapping memory correctly.
* [`ft_memcpy`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_memcpy.c) : Copy bytes from one buffer to another. The memory areas must not overlap. Use memmove if the memory areas do overlap.

### Functions from `<string.h>` library
* [`ft_strlen`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strlen.c) : Get the length of a string.
* [`ft_strchr`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strchr.c) : Find the first occurrence of a character in a string.
* [`ft_strrchr`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strrchr.c) : Find the last occurrence of a character in a string.
* [`ft_strnstr`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strnstr.c) : Locate a substring in a string.
* [`ft_strncmp`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strncmp.c) : Compare two strings, up to a given length.
* [`ft_strdup`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strdup.c) : Create a duplicate of a string, using `malloc`.
* [`ft_strlcpy`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strlcpy.c) : Copy up to size - 1 characters from string src to dst.
* [`ft_strlcat`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strlcat.c) : Concatenates the start of the string src to the end of dst with -1 of the size.

### Non-standard functions
* [`ft_itoa`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_itoa.c) : Convert integer to ASCII string.
* [`ft_substr`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_substr.c) : Get a substring from string.
* [`ft_strtrim`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strtrim.c) : Trim beginning and end of string with the specified substring.
* [`ft_strjoin`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strjoin.c) : Concatenate two strings into a new string, using `calloc`.
* [`ft_split`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_split.c) : Split string, with specified character as delimiter, into an array of strings.
* [`ft_strmapi`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_strmapi.c) : Create new string from a string modified with a specified function.
* [`ft_striteri`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_striteri.c) : Modify a string with a given function.
* [`ft_putchar_fd`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_putchar_fd.c) : Output a character to given file.
* [`ft_putstr_fd`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_putstr_fd.c) : Output string to given file.
* [`ft_putendl_fd`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_putendl_fd.c) : Output string to given file with newline.
* [`ft_putnbr_fd`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_putnbr_fd.c) : Output integer to given file.

### Linked list functions *(bonus)*
* [`ft_lstnew`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstnew_bonus.c) : Create new list.
* [`ft_lstsize`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstsize_bonus.c) : Count elements of a list.
* [`ft_lstlast`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstlast_bonus.c) : Find last element of list.
* [`ft_lstadd_back`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstadd_back_bonus.c) : Add new element at end of list.
* [`ft_lstadd_front`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstadd_front_bonus.c) : Add new element at beginning of list.
* [`ft_lstdelone`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstdelone_bonus.c) : Delete element from list.
* [`ft_lstclear`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstclear_bonus.c) : Delete sequence of elements of list from a starting point.
* [`ft_lstiter`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstiter_bonus.c) : Apply function to content of all list's elements.
* [`ft_lstmap`](https://github.com/Javisanchezf/42Malaga-Libft/blob/main/ft_lstmap_bonus.c) : Apply function to content of all list's elements into new list.

## Requirements
The library is written in __C language__ and needs the `gcc` compiler, with `<stdlib.h>` and `<unistd.h>` standard libraries to run.

## Instructions

### 1. Download the repository

To download the repository, go to the console and run:

For __basic__ functions:
```
git clone https://github.com/Javisanchezf/42Malaga-libft.git 42Malaga-libft
cd 42Malaga-libft
```

### 2. Compiling the library

To compile the library, go to its path and run:

For __basic__ functions:
```
make all
```

For __bonus__ functions:
```
make bonus
```

### 3. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, go to the path and run:
```
make fclean
```

### 4. Using it in your code

To use the library functions in your code, simply include this header:
```
#include "libft.h"
```

## Testing
This library have been tested with the normal and strict mode of [Francinette](https://github.com/xicodomingues/francinette) to the date of 12/12/2022.

## License
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).

You are free to:
* Share: copy and redistribute the material in any medium or format.
* Adapt: remix, transform, and build upon the material.

Under the following terms:
* Attribution: You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
* NonCommercial: You may not use the material for commercial purposes.
* ShareAlike: If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

<h3 align = right>Share the content!</h3>

[<img src="https://github.com/Javisanchezf/media/blob/main/whatsapp-icon.png" width="50" height="50" align = right></img>](https://api.whatsapp.com/send?text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github.%20%0ahttps://github.com/Javisanchezf/42Malaga-Libft)
[<img src="https://github.com/Javisanchezf/media/blob/main/telegram-icon.webp" width="50" height="50" align = right></img>](https://t.me/share/url?url=https://github.com/javisanchezf/42Malaga-Libft&text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github.)
[<img src="https://github.com/Javisanchezf/media/blob/main/twitter-icon.png" width="50" height="50" align = right></img>](https://twitter.com/intent/tweet?url=https://github.com/Javisanchezf/42Malaga-Libft&text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github)
[<img src="https://github.com/Javisanchezf/media/blob/main/linkedin-icon.png" width="50" height="50" align = right></img>](https://www.linkedin.com/sharing/share-offsite/?url=https://github.com/javisanchezf/42Malaga-Libft)
