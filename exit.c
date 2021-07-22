#include "minishell.h"



int		ft_exit(char **args)
{
	int		ret;
	
	ret = 0;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (ft_isnum(args[1]) == SUCCESS && !args[2])
		ret = ft_atoi(args[1]);
	else if (args[1] && ft_isnum(args[1]) == FAILURE)
	{
		ret = 255;
		ft_putstr_fd("minishell: exit:", STDOUT_FILENO);
		ft_putstr_fd(args[1], STDOUT_FILENO);
		ft_putstr_fd("numeric argument required\n", STDOUT_FILENO);
	}
	else if (ft_isnum(args[1]) == SUCCESS && ft_isnum(args[2]) == SUCCESS)
	{
		ret = 1;
		ft_putstr_fd("minishell: exit: too many arguments", STDOUT_FILENO);
	}
	return(ret);
}