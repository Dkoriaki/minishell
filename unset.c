#include "minishell.h"

int		env_variable_len(char *str)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != '=')
	{
		len++;
	}
	//printf("|%s| len = %d\n", str, len);
	return (len);
}

t_env	*ft_unset(char *str, t_env *env)
{
	t_env	*cur;
	t_env	*prec;

	cur = env;
	prec = env;
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