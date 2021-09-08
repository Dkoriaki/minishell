#include "minishell.h"

char	*ft_env_value(char *str, t_env *env)
{
	int		len;
	t_env	*cur;
	int		i;
	int		j;
	char	*ret;

	len = ft_strlen(str);
	cur = ft_find_env(str, env);
	if (cur == NULL)
		return (NULL);
	i = ft_strlen(cur->str) - (len + 1);
	ret = malloc(sizeof(char*) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = len + 1;
	j = 0;
	while (cur->str[i])
	{
		ret[j] = cur->str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

t_env	*ft_find_env(char *str, t_env *env)
{
	int		len;

	len = ft_strlen(str);
	while (env)
	{
		if (ft_strncmp(str, env->str, len) == 0 && (env->str[len] == '='
				|| env->str[len] == '\0'))
			return (env);
		env = env->next;
	}
	return (NULL);
}

int		env_variable_len(char *str)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != '=')
	{
		len++;
	}
	return (len);
}

t_env	*ft_unset(char *str, t_env *env)
{
	t_env	*cur;
	t_env	*prec;

	cur = env;
	prec = env;
	if (ft_find_env(str, env) == NULL)
	{
		write(STDOUT_FILENO, "\nLOLOLOL\n", 9);
		return (env);
	}
	if (!env)
		return (NULL);
	if (ft_strncmp(str, env->str, env_variable_len(env->str)) == 0)
	{
		env = env->next;
		free(cur);
		return (env);
	}
	while (cur)
	{
		prec = cur;
		cur = cur->next;
		if (ft_strncmp(str, cur->str, env_variable_len(cur->str)) == 0)
		{
			prec->next = cur->next;
			free(cur);
			return (env);
		}
	}
	return (env);
}