#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE 32

typedef struct	s_env {
	char			*str;
	struct s_env	*next;
}				t_env;

int			ft_strcmp(char *, char *);
void			ft_sort_env(char **envp);
t_env		*ft_init_env(char **envp);
void    	print_lst(t_env *env);

//------- CD -------//

int		ft_cd(char *);

//------------------//

//------- GNL -------//

int		ft_strlen(char *str, int m);
char	*ft_strjoin(char *s1, char *s2);
int		ft_eol(char *str);
int		ft_return(char **line, char *result, char **tmp, int ret);
int		get_next_line(int fd, char **line);
char	*ft_substr(char *str, unsigned int start, int len);
char	*ft_null(void);
char	*ft_result(char *buffer, char *result, int ret);

//-------------------//

#endif