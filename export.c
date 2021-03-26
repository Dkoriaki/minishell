#include "minishell.h"

/*int		ft_env_len(t_env *env)
{
	int		i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

void	ft_list_to_str(t_env *env)
{
	int		len;

	len = ft_env_len(env);

}*/


/*
void	ft_sort_env(char **envp)
{
	char	*tmp;
	int		i;
	int		j;
	int		env_len;

	tmp = NULL;
	i = 0;
	j = 0;
	env_len = ft_env_len(envp);
	while (i < env_len)
	{
		j = 0;
		while (j < env_len - 1)
		{
			if (ft_strcmp(envp[j], envp[j + 1]) > 0)
			{
				tmp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (envp[i])
	{
		printf("%s", envp[i]);
		i++;
	}
}*/