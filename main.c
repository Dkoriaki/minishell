#include "minishell.h"

int	ft_cd(char *directory)
{
	if (chdir(directory) == 0)
		return(SUCCESS);
	printf("CHDIR error\n");
	return (FAILURE);
}

void	ft_pwd(void)
{
	char	path[PATH_MAX];
	printf("%s\n", getcwd(path, sizeof(path)));
}

int main(int ac, char **av, char **envp) 
{    
	(void)ac;
	(void)av;
    char 	*str;
	t_env	*env;
	char	**test;

	str = NULL;
	env = NULL;
	env = ft_init_env(envp);
	ft_export(NULL, NULL, env);
	ft_export("ZT", "", env);
	printf("\n\n\n-------------------------------------\n\n\n");
	ft_export(NULL, NULL, env);
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
    return 0; 
}