#include <unistd.h>
#include <stdio.h>

int mygetchar(void)
{
        static char buf[BUFSIZ];
        static char *bufp = buf;
        static int i = 0;

        if (i == 0)
        {
                i = read(0, buf, 1);
                bufp = buf;
        }
        if ( --i >= 0 )
        {
                return  *bufp++;
        }

        return EOF;
}
int main ()
{
	int c;

	while ((c = mygetchar()) != EOF)
		putchar(c);
	return (0);
}
