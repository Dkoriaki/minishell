#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdio.h>

void	ls(void)
{
	char	*argv[] = {"/bin/ls"};
	char	*newargv[] = {"/bin/ls", NULL};
	printf("yes aye!!!111\n");
	execve(argv[0], newargv, NULL);
	perror("execve");
	printf("yes aye643634656436");
}

int	main(void)
{
	ls();
	return (0);
}
/*
int		main(void)
{
	int fd_redir;
    int    stdout_save;

    fd_redir = open("test2", O_WRONLY|O_CREAT|O_TRUNC, 0666);

    stdout_save = dup(STDOUT_FILENO);
    write(STDOUT_FILENO, "writing on stdout1\n", 19);
    dup2(fd_redir, STDOUT_FILENO);

    close(fd_redir);
    write(STDOUT_FILENO, "writing on test\n", 18);

    dup2(stdout_save, STDOUT_FILENO);
    close(stdout_save);
    write(STDOUT_FILENO, "writing on stdout2\n", 19);
	return (0);
}*/