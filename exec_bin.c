#include "minishell.h"

int		bin_fonction(char **argv, t_env *env)
{
	char	**tab;
	char	*path;
	int		i;

	i = 0;
	path = ft_env_value("PATH", env);
	tab = ft_split(path, ':');
	while (tab[i])
	{
		bin_is_exist(tab[i], argv);
		//printf("tab[i] = %s\n", tab[i]);
		i++;
	}
	return (0);
}

int		bin_is_exist(char *path, char **cmd)
{
	struct stat sb;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	path = ft_strjoin(tmp, cmd[0]);
	free(tmp);
	if (stat(path, &sb) == 0)
		exec_bin(path, cmd);
		//execve(path, cmd, NULL);
	return (0);
}

int		exec_bin(char *path, char **cmd)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		execve(path, cmd, NULL);
	}
	else
		wait(NULL);
	return (0);
}