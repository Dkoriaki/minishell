#include "minishell.h"

// juste "cd revient a HOME"
// Si HOME n'existe pas : "bash: cd: HOME not set"

int	ft_cd(char *directory, t_env *env)
{
	if (chdir(directory) == 0)
		return(SUCCESS);
	printf("CHDIR error\n");
	return (FAILURE);
}

int	ft_save_oldpwd(t_env *env)
{
	char	oldpath[PATH_MAX];
	t_env	*cur;

	getcwd(oldpath, sizeof(oldpath));
	
	cur = ft_find_env("OLDPWD", env);
	if (cur == NULL)
		printf("FAUT CREER UNE VARIABLE CHACAL\n");
	//printf("test : %s\n", cur->str);
	cur->str = ft_change_env("OLDPWD", oldpath);

	return (0);
}