<p align="center" style="margin-bottom: 0px !important;">
  <img width="600" src="https://github.com/mithraskuipers/mithraskuipers/blob/master/readme_srcs/42/logo.png?raw=true" alt="42_Network_Amsterdam" align="center"> </p>
<h1 align="center" style="margin-top: 0px;">Get Next Line [![mikuiper's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cl483ajsd008309l6suq9l256/project/2408182)](https://github.com/mithraskuipers)
</h1>

<p align="center" style="margin-top: 0px;">
<img src="https://forthebadge.com/images/badges/made-with-c.svg"/>
<img src="https://forthebadge.com/images/badges/built-with-love.svg"/>
</p>

## :book: About the project

<em>Summary</em>: This project is about programming a function that returns a line read from a file descriptor.

<em>Goals</em>: This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in  C  programming: static variables.

<table>
<tbody>
<tr>
<td>Function name</td>
<td>get_next_line</td>
</tr>
<tr>
<td>Prototype</td>
<td>char *get_next_line(int fd);</td>
</tr>
<tr>
<td>Turn in files</td>
<td>get_next_line.c, get_next_line_utils.c, get_next_line.h</td>
</tr>
<tr>
<td>Parameters</td>
<td>fd: The file descriptor to read from</td>
</tr>
<tr>
<td>Return value</td>
<td>
<p>Read line: correct behavior</p>
<p>NULL: there is nothing else to read, or an error occurred</p>
</td>
</tr>
<tr>
<td>External functs.</td>
<td>read, malloc, free</td>
</tr>
<tr>
<td>Description</td>
<td>Write a function that returns a line read from a file descriptor</td>
</tr>
</tbody>
</table>
<p>&nbsp;</p>

##  Usage

### :computer: Requirements

**`gcc` compiler**

### :hammer_and_wrench: Building

To use the get_next_line function in your code, include its header:

```C
#include "get_next_line.h"
```
And at compilation time, add the corresponding source files and an optional BUFFER_SIZE flag (default = 42).


```bash
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

### :runner: Running

To use the code, provide a main that obtains a file descriptor using open() and uses that file descriptor as the get_next_line function argument. For example..

```bash
int main(void)
{
	char *line;
	int i;
	int fd;
	fd1 = open("files/file.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
```

#### Questions?
Please connect with me on LinkedIn or send an e-mail.

<a href="https://www.linkedin.com/in/mithraskuipers/"><img align=center src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" /></a>
<a href="mailto:mithraskuipers@gmail.com"><img align=center src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" /></a>
