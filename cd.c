#include "minishell.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_cd(char *directory)
{
	if (chdir(directory) == 0)
		return(SUCCESS);
	printf("CHDIR error\n");
	return (FAILURE);
}

int		ft_strncmp(char *s1, char *s2, int len)
{
	int		i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < len))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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
	char	**test;

	str = NULL;
	env = NULL;
	env = ft_init_env(envp);
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