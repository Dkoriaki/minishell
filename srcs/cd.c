#include "minishell.h"

// juste "cd revient a HOME"
// Si HOME n'existe pas : "bash: cd: HOME not set"

void	go_to_home(t_env *env)
{
	t_env	*cur;
	char	*str;

	cur = ft_find_env("HOME", env);
	if (cur == NULL)
		printf("HOME DOES NOT EXIST\n");
	str = cur->str;
	int i = 1;
	while (str[i - 1] != '=')
		i++;
	if (chdir(&str[i]) != 0)
		printf("CD HOME NOT WORK\n");
	ft_save_pwd(env);
}

int	ft_save_pwd(t_env *env)
{
	char	path[PATH_MAX];
	t_env	*cur;

	getcwd(path, sizeof(path));
	cur = ft_find_env("PWD", env);
	if (cur == NULL)
		printf("PWD DOES NOT EXIST\n");
	cur->str = ft_change_env("PWD", path);
	return (SUCCESS);
}

int	ft_cd(char *directory, t_env *env)
{
	ft_save_oldpwd(env);
	if (!directory)
		go_to_home(env);
	else if (chdir(directory) == 0)
	{
		ft_save_pwd(env);
		return(SUCCESS);
	}
	else
		printf("\n-------- CD ERROR --------\n");
	return (FAILURE);
}

int	ft_save_oldpwd(t_env *env)
{
	char	oldpath[PATH_MAX];
	t_env	*cur;

	getcwd(oldpath, sizeof(oldpath));
	
	cur = ft_find_env("OLDPWD", env);
	if (cur == NULL)
		printf("FAUT CREER UNE VARIABLE OLDPWD CHACAL\n");
	//printf("test : %s\n", cur->str);
	cur->str = ft_change_env("OLDPWD", oldpath);

	return (SUCCESS);
}