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
# define SUCCESS 0
# define FAILURE 1

typedef struct	s_env {
	char			*str;
	struct s_env	*next;
}				t_env;


void		ft_print_env_value(char *str, t_env *env);
int			ft_exit(char **args);
int			exec_bin(char *path, char **cmd, char **env_cpy);
int			bin_is_exist(char *path, char **cmd, t_env *env);
int			is_exist(char *path);
char		*ft_env_value(char *str, t_env *env);
int			bin_fonction(char **argv, t_env *env);
void		ft_echo(char *str, char *n);
char		**ft_split(char const *str, char c);
void		go_to_home(t_env *env);
void		ft_env(t_env *env);
t_env  		*lst_add_back(t_env *env, char *str);
t_env		*ft_find_env(char *str, t_env *env);
t_env		*ft_unset(char *, t_env *);
t_env		*ft_init_env(char **envp);
void    	print_lst(t_env *env);
int			env_variable_len(char *);




//------- CD -------//

int			ft_cd(char *directory, t_env *env);
int			ft_save_oldpwd(t_env *env);
int			ft_save_pwd(t_env *env);

//------- UTILS -------//

int			ft_atoi(char *str);
void		ft_putstr_fd(char *str, int fd);
int			ft_isnum(char *str);
int			ft_charchr(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(char *, char *);
int			ft_strncmp(char *, char *, int);
char		*ft_strdup(char *s1);
int			ft_strlen(char *str);
char		*ft_strjoin_env(char *s1, char *s2);

//------- EXPORT -------//

int			ft_env_len(t_env *env);
int			ft_array_len(char **array);
char		**ft_sort_env(char **envp);
char		**ft_list_to_array(t_env *env);
void		print_env_array(char **array);
char		*ft_change_env(char *str, char *value);
void		ft_export(char *str, char *value, t_env *env);

//------- GNL -------//

int		ft_strlen_gnl(char *str, int m);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_eol(char *str);
int		ft_return(char **line, char *result, char **tmp, int ret);
int		get_next_line(int fd, char **line);
char	*ft_substr(char *str, unsigned int start, int len);
char	*ft_null(void);
char	*ft_result(char *buffer, char *result, int ret);

//-------------------//

#endif