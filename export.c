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

int		ft_array_len(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_sort_env(char **envp)
{
	char	*tmp;
	int		i;
	int		j;
	int		env_len;

	tmp = NULL;
	i = 0;
	j = 0;
	env_len = ft_array_len(envp);
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
	return (envp);
}

char	**ft_list_to_array(t_env *env)
{
	int		nb_lines;
	int		i;
	char	**tab;

	i = 0;
	nb_lines = ft_env_len(env);
	//print_lst(env);
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
	
	return (tab);
}

void	print_env_array(char **array)
{
	int		y;
	int		x;
	int		equal;

	
	y = 0;
	while (array[y])
	{
		x = 0;
		equal = 0;
		write(1, "declare -x ", 11);
		while(array[y][x])
		{
			write(1, &array[y][x], 1);
			if (array[y][x] == '=')
			{
				write(1, "\"", 1);
				equal = 1;
			}
			x++;
		}
		if (equal == 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
		y++;
	}
}

char	*ft_change_env(char *str, char *value, t_env *env)
{
	char	*out;

	out = ft_strjoin_env(str, value);
	return(out);
}

void	ft_export(char *str, char *value, t_env *env)
{
	char	**tab;
	t_env	*cur;
	char	*tmp;
	//If 0 arguments, 
	if(!str && !value)
	{
		tab = ft_list_to_array(env);
		tab = ft_sort_env(tab);
		print_env_array(tab);
		return ;
	}
	//IF str existe deja =
	cur = ft_find_env(str, env);
	if (cur != NULL)
	{
		if (!value)
			return ;
		cur->str = ft_change_env(str, value);
		return ;
	}
	//cas : export -> "str=value" && "str="
	if (value)
	{
		tmp = ft_strjoin_env(str, value);
		env = lst_add_back(env, tmp);
	}
	else // cas : "export str"
		env = lst_add_back(env, str);
}