# **Get Next Line**
This project was graded <strong>125/100</strong>.


## 📒 **About**
In this project you will implement a very useful function, that exists in higher level languages, but not in C. You must read a line from a given file descriptor (including the line break) and return it in a new allocated string. Yes, you will find it very boring to do, but it will come in handy at the right moment. You'll learn about static variables, the read() and open() functions and file descriptors.


## 🔧 **Implementation**
<table>
	<thead>
		<tr>
			<th>Part</th>
			<th>File Name</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan = 3>Mandatory</td>
			<td>get_next_line.c</td>
			<td>Contains functions specifically developed for this project</td>
		</tr>
		<tr>
			<td>get_next_line_utils.c</td>
			<td>Contains functions from libft with a few changes to fit in the project</td>
		</tr>
		<tr>
			<td>get_next_line.h</td>
			<td>Contains the headers of all .c files</td>
		</tr>
		<tr>
			<td rowspan = 3>Bonus</td>
			<td>get_next_line_bonus.c</td>
			<td>Contains functions specifically developed for this project</td>
		</tr>
		<tr>
			<td>get_next_line_utils_bonus.c</td>
			<td>Contains functions from libft with a few changes to fit in the project</td>
		</tr>
		<tr>
			<td>get_next_line_bonus.h</td>
			<td>Contains the headers of all .c files</td>
		</tr>
	</tbody>
</table>


## 📦 **Compilation**
This project does not hold a Makefile for compilation, but in case you have a `main.c` file that uses this functions, you can link every file in the same executable like so:

```sh
$ cc -Wall -Wextra -Werror main.c (REPLACE BY PATH TO THIS FOLDER)/*.c
```

Dont forget to include the `.h` files!

## 💫 **Testing**

This project was tested using the [gnlTester](https://github.com/Tripouille/gnlTester) and manual revision only.


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).

