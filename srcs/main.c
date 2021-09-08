#include "minishell.h"



void	ft_pwd(void)
{
	char	path[PATH_MAX];
	getcwd(path, sizeof(path));
	write(STDOUT_FILENO, &path, ft_strlen(path));
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_reset_stdout(int fd)
{
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		//close(fd);
	}
}

void	ft_check_redirection(int fd, char **tab)
{
	int		i;
	int fd_redir;

	(void)fd;
	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], ">") == 0)
		{
			fd_redir = open(tab[i + 1], O_WRONLY|O_CREAT|O_TRUNC, 0666);
			dup2(fd_redir, STDOUT_FILENO);
			close(fd_redir);
			return ;
		}
		i++;
	}
}

int main(int ac, char **av, char **envp) 
{    
	(void)ac;
	(void)av;
    char 	*str;
	t_env	*env;
	int    stdout_save;

	str = NULL;
	env = NULL;
	env = ft_init_env(envp);

	//char	*test[] = {"lp",  NULL};
	//	execve(test[0], test, NULL);

	
	int	ret = 1;
	char	**tab;
	stdout_save = dup(STDOUT_FILENO);
	//ft_print_env_value("$USE", env);
	
	while((ret = get_next_line(0, &str)) > 0)
	{
		
		tab = ft_split(str, ' ');
		ft_check_redirection(stdout_save, tab);
		if (ft_strncmp(tab[0], "cd", 2) == 0)
			ft_cd(tab[1], env);
		else if (ft_strncmp(tab[0], "pwd", 3) == 0)
			ft_pwd();
		else if (ft_strncmp(tab[0], "echo", 4) == 0)
			ft_echo(tab[1], tab[2]);
		else if (ft_strncmp(tab[0], "env", 3) == 0)
			ft_env(env);
		//Va falloir modifier ca
		//------------------------------------//
		else if (ft_strncmp(tab[0], "export", 6) == 0 && (tab[1] == NULL || ft_strcmp(">", tab[1]) == 0))
		{
			//write(STDOUT_FILENO, "P", 1);
			ft_export(NULL, NULL, env);
		}
		//------------------------------------//
		else if (ft_strncmp(tab[0], "export", 6) == 0)
			ft_export(tab[1], tab[2], env);
		else if (ft_strncmp(tab[0], "unset", 5) == 0)
			ft_unset(tab[1], env);
		else if (ft_strncmp(str, "exit", 4) == 0)
			exit(ft_exit(tab));
		else
			bin_fonction(tab, env);
		ft_reset_stdout(stdout_save);
	}
    return 0; 
}
