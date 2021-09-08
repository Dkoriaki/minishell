#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_list
{
	char			**args;
	int				pipe[2];
	int				type;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int show_error(char *str)
{
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

static void		*ft_strfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return ((void *)0);
}

static int		ft_nbwrds(char const *s, char c)
{
	int	i;
	int	j;

	if (!s)
		return (-1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static int		w(char const *s, int i, char c)
{
	while (s[i] != c && s[i])
		i++;
	return (i + 1);
}

char			**ft_split(char const *str, char c)
{
	char	**out;
	int		i[3];

	if ((ft_nbwrds(str, c) == -1)
		|| !(out = (char **)malloc(sizeof(char *) * (ft_nbwrds(str, c) + 1))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		if (str[i[0]] != c)
		{
			if (!(out[i[1]] = (char *)malloc(sizeof(char) * w(str, i[0], c))))
				return (ft_strfree(out));
			i[2] = 0;
			while (str[i[0]] != c && str[i[0]])
				out[i[1]][i[2]++] = str[i[0]++];
			out[i[1]][i[2]] = '\0';
			i[1]++;
		}
		else
			i[0]++;
	}
	out[i[1]] = NULL;
	return (out);
}


//----------------------------------------------------


int		is_empty_list(t_list *cmds)
{
    if (cmds == NULL)
        return (1);
    return (0);
}

t_list	*create_cell(int i, int nb)
{
	t_list	*cmd;

	if (!(cmd = malloc(sizeof(t_list))))
		return NULL;
	if (nb == 3)
	{
		if (i == 0)
		{
			cmd->type = 0;
			cmd->args = ft_split("/bin/ls", ',');
			cmd->previous = NULL;
			//cmd->next = NULL;
		}
		else if (i == 1)
		{
			cmd->type = 0;
			cmd->args = ft_split("/usr/bin/greep,a", ',');
		}
		else if (i == 2)
		{
			cmd->type = 1;
			cmd->args = ft_split("/usr/bin/wc", ',');
		}
		cmd->next = NULL;
	}
	if (nb == 2)
	{
		if (i == 0)
		{
			cmd->type = 0;
			cmd->args = ft_split("/bin/ls", ',');
			cmd->previous = NULL;
			//cmd->next = NULL;
		}
		else if (i == 1)
		{
			cmd->type = 1;
			//cmd->args = ft_split("/usr/bin/wc,-w", ',');
			cmd->args = ft_split("/usr/bin/grep,txt", ',');
		}
		cmd->next = NULL;
	}
	return (cmd);
}

t_list  *lst_add_back(t_list *cmds, int i, int nb)
{
	t_list	*new;
	t_list	*cur;

	new = create_cell(i, nb);
	//printf("i = %d new->args[0] = %s\n", i, new->args[0]);
	cur = cmds;
	if (is_empty_list(cmds))
		return (new);
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = new;
	new->previous = cur;

	return (cmds);
}

//---------------------------------------------------------------------------
//	On creer la liste chainée avec 3 maillon avec les valeurs suivantes:
//	1 - ls
//	2 - grep "a"
//	3 - wc
//---------------------------------------------------------------------------

t_list	*init_list(t_list *cmds, int nb)
{
	int	i;

	i = 0;
	if (nb == 3)
	{
		while (i < 3)
		{
			cmds = lst_add_back(cmds, i, nb);
			i++;
		}
	}
	if (nb == 2)
	{
		while (i < 2)
		{
			cmds = lst_add_back(cmds, i, nb);
			i++;
		}
	}
	return (cmds);
}

void    print_lst(t_list *env)
{
	int		i;

    while (env)
    {
		i = 0;
        /*while (env->args[i])
		{
			printf("%s\n", env->args[i]);
			i++;
		}*/
		printf("%s\n", env->args[0]);
		//if (env->previous)
		//	printf("prev = %s\n", env->previous->args[0]);
        env = env->next;
    }
    //printf("\n");
}

int		exec_cmd(t_list *cmd, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;

	ret = EXIT_FAILURE;
	if (pipe(cmd->pipe))
		return (ret);
	pid = fork();
	if (pid < 0)
		return (ret);
	else if (pid == 0)
	{
		if (cmd->type == 0)
			dup2(cmd->pipe[1], STDOUT_FILENO);
		if (cmd->previous)
			dup2(cmd->previous->pipe[0], STDIN_FILENO);
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
			//printf("error: cannot execute ");
			//printf("%s\n", cmd->args[0]);
		}
		exit(ret);
	}
	else
	{
		//printf("cmd->args[0] = %s\n", cmd->args[0]);
		waitpid(pid, &status, 0);
		//printf("cmd->args[0] = %s\n", cmd->args[0]);
		close(cmd->pipe[1]);
		if (!cmd->next)
			close(cmd->pipe[0]);
		if (cmd->previous)
			close(cmd->previous->pipe[0]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int		exec_cmds(t_list *cmd, char **env)
{
	int		ret;

	while(cmd)
	{
		//printf("cmd->args[0] = %s\n", cmd->args[0]);
		ret = exec_cmd(cmd, env);
		cmd = cmd->next;
	}
	return (ret);
}

void	


int		main(int ac, char **av, char **env)
{
	t_list	*cmds;
	
	cmds = NULL;

	cmds = init_list(cmds, 3);
	//print_lst(cmds);
	exec_cmds(cmds, env);
	exec_keyboard_redir();
	return (0);
}
