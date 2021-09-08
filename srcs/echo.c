#include "minishell.h"

void	ft_echo(char *str, char *n)
{
	int		i;
	int		newline;

	i = 0;
	newline = 0;
	if (ft_strcmp(str, "-n") == 0)
	{
		newline = 1;
		str = n;
	}
	while (str[i])
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
	if (newline)
		return ;
	write(STDOUT_FILENO, "\n", 1);
}