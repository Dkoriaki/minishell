#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdio.h>

void	ls(void)
{
	char	*argv[] = {"/bin/ls"};
	char	*newargv[] = {"/bin/ls", NULL};
	execve(argv[0], newargv, NULL);
	perror("execve");
}

void	grep(void)
{
	char	*argv[] = {"/usr/bin/grep"};
	char	*newargv[] = {"/usr/bin/grep", "get", NULL};
	execve(argv[0], newargv, NULL);
	perror("execve");
}

void	wc(void)
{
	char	*argv[] = {"/usr/bin/wc"};
	char	*newargv[] = {"/usr/bin/wc", NULL};
	execve(argv[0], newargv, NULL);
	perror("execve");
}

void	exec_cmd(int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
}

int	main(void)
{
	int		i = 0;
	//ls();
	//grep();
	while (i < 3)
	{
		exec_cmd(i);
		i++;
	}
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