#include <stdio.h>
#include <unistd.h>
int ft_getchar ()
{
	char buf[1];
	int n = read(0, buf, 1);

	if (n < 1)
		printf("Read failed");
	return (buf [0]);
}
int main ()
{
	int c;

	while ((c = ft_getchar()) != EOF)
		putchar(c);
	return (0);
}
