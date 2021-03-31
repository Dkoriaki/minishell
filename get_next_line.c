#include "minishell.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1, 1) + ft_strlen_gnl(s2, 1);
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s1)
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[j])
		{
			result[i + j] = s2[j];
			j++;
		}
	result[i + j] = '\0';
	return (result);
}

int		ft_return(char **line, char *result, char **tmp, int ret)
{
	int	len;

	if (ret < 0)
		return (-1);
	if (ret == 0 && ft_eol(result) == 0)
	{
		*line = result;
		*tmp = NULL;
		return (0);
	}
	if (ft_eol(result) == 0)
	{
		*line = result;
		return (1);
	}
	len = ft_strlen_gnl(result, 1) - (ft_strlen_gnl(result, 2) + 1);
	*line = ft_substr(result, 0, ft_strlen_gnl(result, 2));
	*tmp = ft_substr(result, ft_strlen_gnl(result, 2) + 1, len);
	free(result);
	result = NULL;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static	char	*tmp;
	char			*buffer;
	char			*result;

	if (fd <= -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 0;
	result = (tmp) ? tmp : ft_null();
	if (ft_eol(result) == 0)
	{
		while (ft_eol(result) == 0 && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
			result = ft_result(buffer, result, ret);
	}
	if (ret < BUFFER_SIZE || ft_eol(result) == 1)
	{
		free(buffer);
		return (ft_return(line, result, &tmp, ret));
	}
	return (-1);
}