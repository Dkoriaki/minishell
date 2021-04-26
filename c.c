#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	(void)ac;
	int		fd;

	fd = open(av[1], O_WRONLY|O_CREAT|O_APPEND, 0666);
	write(fd, "salut\n", 6);
	return (0);
}