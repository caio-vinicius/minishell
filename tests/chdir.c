#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char s[100];

	printf("currentdir %s\n", getcwd(s, 100));
	chdir("..");
	printf("currentdir %s\n", getcwd(s, 100));

	return (0);
}
