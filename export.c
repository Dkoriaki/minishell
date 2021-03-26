#include "minishell.h"

int		ft_env_len(t_env *env)
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

char	**ft_list_to_array(t_env *env)
{
	int		nb_lines;
	int		i;
	char	**tab;

	i = 0;
	nb_lines = ft_env_len(env);
	print_lst(env);
	tab = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	if (!tab)
		return (NULL);
	while (env && i < nb_lines)
	{
		tab[i] = ft_strdup(env->str);
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	int	y = 0;
	while (tab[y])
	{
		printf("tab[%d] =    %s\n", y, tab[y]);
		y++;
	}
	return (tab);
}

/*t_env	ft_export(char *str, char *value, t_env *env)
{
	//If 0 arguments, 
	if(!str && !value)
	{
		//AFFICHAGE
		//convertir la list en tab

	}
	//IF str existe deja =

	//IF !str =
}*/