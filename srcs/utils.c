#include "minishell.h"

void	ft_print_env_value(char *str, t_env *env)
{
	int		i;
	char	*ret;

	i = 1;
	ret = ft_env_value(&str[i], env);
	if (ret == NULL)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd(ret, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(ret);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negativ;
	int	nb;
	int	count;

	i = 0;
	negativ = 0;
	nb = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ++;
		count++;
		if (count > 1)
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return ((negativ != 0) ? -nb : nb);
}

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_isnum(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] <= '0' || str[i] >= '9')
				return (FAILURE);
			i++;
		}
	}
	return (SUCCESS);
}

int	ft_charchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		mallen;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	mallen = ft_strlen(s1) + ft_strlen(s2);
	if (!(out = (char *)malloc(sizeof(char) * mallen + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		out[i++] = s1[j++];
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}

char	*ft_strjoin_env(char *s1, char *s2)
{
	int		i;
	int		j;
	int		mallen;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	mallen = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(out = (char *)malloc(sizeof(char) * mallen + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		out[i++] = s1[j++];
	out[i++] = '=';
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}
