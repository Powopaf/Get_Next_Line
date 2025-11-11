#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("./test", O_RDONLY);
	char *a = get_next_line(fd);
	while (a != NULL)
	{
		printf("%s", a);
		a = get_next_line(fd);
	}
	return (1);
}
