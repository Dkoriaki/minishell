#include "minishell.h"



void	ft_pwd(void)
{
	char	path[PATH_MAX];
	printf("%s\n", getcwd(path, sizeof(path)));
}

void	ft_check_redirection(int fd, char **tab)
{
	int		i;
	int fd_redir;

	i = 0;
	dup(fd);
	if (fd != STDOUT_FILENO)
	{
		printf("PPPPPPPPPPPP");
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
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
	char	**test;
	int    stdout_save;

	str = NULL;
	env = NULL;
	env = ft_init_env(envp);


	/*while (1)
	{
		get_next_line(0, &str);
		if (ft_strcmp(str, "cd") == 0)
			ft_cd("..");
		else if (ft_strcmp(str, "pwd") == 0)
			ft_pwd();
		else if (ft_strcmp(str, "env") == 0)
			print_lst(env);
		else if (ft_strcmp(str, "exit") == 0)
			exit(1);
		else if (ft_strncmp(str, "unset", 5) == 0)
			env = ft_unset("LANG", env);
		//else if (ft_strncmp(str, "export", 6) == 0)
		//	env = ft_export("daniel", "bg", env);
		else
			printf("commande non reconnu\n");
	}*/
	
	int	ret = 1;
	char	**tab;
	stdout_save = dup(STDOUT_FILENO);
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
		else if (ft_strncmp(tab[0], "export", 6) == 0 && tab[1] == NULL)
			ft_export(NULL, NULL, env);
		//------------------------------------//
		else if (ft_strncmp(tab[0], "export", 6) == 0)
			ft_export(tab[1], tab[2], env);
		else if (ft_strncmp(tab[0], "unset", 5) == 0)
			ft_unset(tab[1], env);
		else if (ft_strncmp(str, "exit", 4) == 0)
			exit(1);
	}
    return 0; 
}