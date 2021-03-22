#include "minishell.h"

int	ft_cd(char *directory)
{
	if (chdir(directory) == 0)
		return(0);
	printf("CHDIR error\n");
	return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
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

	str = NULL;
	env = NULL;
	env = ft_init_env(envp);
	while (1)
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
		else
			printf("commande non reconnu\n");
	}
    return 0; 
}