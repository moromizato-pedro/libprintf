_This project has been created as part of the 42 curriculum by pedrohe3_

# Description
The ft_printf project has as objective to introduce the variadic funtions thorugh the development of a function based on the real printf.

# Instructions
To compile the code a few steps are necessary:
- Prepare the libraries.
- Include the necessary libraries.
- Compilation and linking.
- Run the program.

### Preparing the libraries
The Makefile is there simplify the creation of all the .o files to build the libraries, and actually build them as well, by generating the .a files with the command:
	
	make

### Including the necessary libraries
The only library necessary in your source code is the "ft_printf.c" and just add the line bellow in the source file to include it:
	
	#include "ft_printf.c"

If no source code is already prepared, the code bellow is a simple example that can be used to test the ft_printf function. For the matter of this guide we will refer to "main.c" as the source code that uses the ft_printf function:
```
#include "ft_printf.h"

int	main(void)
{
	char	c = 'a';
	char	*s = "Hello World";

	ft_printf(" %c \n", c);
	ft_printf(" %s \n", s);
	ft_printf(" %p \n", s);
	ft_printf(" %d \n", c);
	ft_printf(" %i \n", c - 49);
	ft_printf(" %u \n", c - 49);
	ft_printf(" %x \n", 17);
	ft_printf(" %X%% \n", 17);
	return (0);
}
```

### Compilation and Linking
To build the executable from the source code, you need the following command:
	
	cc -Wall -Werror -Wextra main.c libftprintf.a -o test
	
The command above links the compiled object code from "main.c" with the static archive libftprintf.a to produce the final executable named "test". All of that can be viewed in different fragments:
- The `cc main.c` compiles the source code (creates an object file, the .o, for the main.c)
	- The object file is the source code transformed to machine code, which is the only language that the computer understands, and copy it into the executable that will be created.
- The `-Wall -Werror -Wextra` are some flags that 42 requires to compile a source file. They ensure to explicit block the compilation and tell the user if something in the code might cause a problem if it is compiled as it is.
- Adding the `libftprintf.a` adds an instruction to the compiler, to link this static archive to the compiled object code from main.c. 
	- Which means it will look for any function that were not created inside the main.c and search for their name at the libftprintf.a.
		- The libftprintf.a is a pre-compiled object file that contains the machine code of all the functions it contains, basically being an easy and faster way to use them, instead of having tons of files with the declaration and implementation of the functions needed.
	- If they are found, it then copies only the machine code referent to those functions from the libftprintf.a, and paste it (or if you preffer, link it) to the executable, in order to guarantee that it has the declaration and implementation of those functions.
- The `-o test` flag indicates that we want to choose the word after the flag to be name of the executable created.
	- This executable will be a standalone binary, that means a file that contains all the machine code necessary to work properly

### Run the program
Finally, after the executable is created, you just need to run the command bellow using the name chosen for the executable:
	`./test`

# Resources
- GeeksforGeeks
- Cmd `man printf`
- In this project AI was used to understand better how the compilation and linking process worked in order to create this guide.

# Algorithm and Data Structure
The algorithm chosen was to use variable lists to iterate through the unknown amount of parameters from the function, and use a while to iterate through all the characters from the format sent to the ft_printf function. It was selected because while iterating the string it is possible to evaluate each character and check for the '%' sign, which is the indicator that an specifier will follow. With that, an auxiliary function was created to parse which specifier was being used, and finally a function for each different specifier was created, which would deal with the parameter and print it accordingly to the specifier used.

