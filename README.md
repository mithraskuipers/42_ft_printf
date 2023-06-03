<p align="center" style="margin-bottom: 0px !important;">
  <img width="600" src="https://github.com/mithraskuipers/mithraskuipers/blob/master/readme_srcs/42/logo.png?raw=true" alt="42_Network_Amsterdam" align="center"> </p>
<h1 align="center" style="margin-top: 0px;">ft_printf <a href="https://github.com/mithraskuipers"><img src="https://badge42.vercel.app/api/v2/cl483ajsd008309l6suq9l256/project/2408182" alt="mikuiper's 42 ft_printf Score" /></a>
</h1>

<p align="center" style="margin-top: 0px;">
<img src="https://forthebadge.com/images/badges/made-with-c.svg"/>
<img src="https://forthebadge.com/images/badges/built-with-love.svg"/>
</p>

## :book: About the project

<em>Summary</em>: The goal of this project is pretty straightforward. You will recode printf(). You will mainly learn about using a variable number of arguments.

<em>Goals</em>: You will discover a popular and versatile C function: printf(). This exercise is a great opportunity to improve your programming skills. It is of moderate difficulty. You will discover variadic functions in C. The key to a successful ft_printf is a well-structured and extensible code.

<table>
<tbody>
<tr>
<td>Program name</td>
<td>libftprintf.a</td>
</tr>
<tr>
<td>Turn in files</td>
<td>Makefile, *.h, */*.h, *.c, */*.c</td>
</tr>
<tr>
<td>Makefile</td>
<td>NAME, all, clean, fclean, re</td>
</tr>
<tr>
<td>External functs.</td>
<td>malloc, free, write, va_start, va_arg, va_copy, va_end</td>
</tr>
<tr>
<td>Libft authorized</td>
<td>Yes</td>
</tr>
<tr>
<td>Description</td>
<td>Write a library that contains ft_printf(), a function that will mimic the original printf()</td>
</tr>
</tbody>
</table>
<p>&nbsp;</p>

<em>Task</em>: You have to recode the printf() function from libc.

The prototype of ft_printf() is:
```c
int ft_printf(const char *, ...);
```

Project requirements:

- Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library.
Using the libtool command is forbidden.
- Your libftprintf.a has to be created at the root of your repository.

## Usage

To use the `ft_printf` library, follow the steps below:

### :computer: Requirements

- `gcc` compiler

### :hammer_and_wrench: Building

1. Clone the repository that contains the `ft_printf` project.
2. Navigate to the root of the repository in your terminal.
3. Run the `make` command to compile the project and create the `libftprintf.a` library.

### :runner: Running

1. After successfully building the project, you can include the `libftprintf.a` library in your own C program.
2. In your C program, include the header file `ft_printf.h` to access the `ft_printf` function.
3. Use the `ft_printf` function in your code, providing the desired format string and any additional arguments.

Here's an example of how to use `ft_printf` in a C program:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The answer is %d\n", 42);
    return 0;
}
```

#### Questions?

If you have any questions or need further assistance, you can also reach out to me by clicking on the badges below:

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mithraskuipers/)
[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:mithraskuipers@gmail.com)
