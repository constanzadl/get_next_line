#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFF_SIZE 32
int ft_getchar (int fd)
{
	//int fd - file descriptor from which we're reading
	//
	char buf[1];
	int n = read(fd, buf, 1);

	//check eof
	if (n < 0)
		return(0);
	//should use putstr
	return (buf [0]);
}

int main(int args, char **argv)
{
	int fd;
	char buf [BUFF_SIZE];
	int n;

	fd = open(argv[1], O_RDWR);
	while ((n = ft_getchar(fd)) != 0)
	{
		//It gets a read fail before it reached EOF. Might not be reaching end of file.
		if (n != '\n')//while n = ft_getchar(fd) != '\n' you putstr.
			putchar(n);
		if (n == '\n') //if it is a new line, append the '\n' at the end of the string.
			putchar('\n');
	}
	return (0);
}
