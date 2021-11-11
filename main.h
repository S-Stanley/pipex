/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:45:27 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/10 20:45:28 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_cmd{
	char	*cmd;
	char	**arg;
}				t_cmd;

typedef struct s_return_value{
	char	*str;
	int		i;
}				t_return_value;

typedef struct s_list {
	int		fd[2];
	char	*cmd1;
	char	*cmd2;
	char	**arg1;
	char	**arg2;
	int		pid;
	char	buffer[4000];
	char	*infile;
	char	*outfile;
	char	**env;
}				t_list;

char			**ft_split(const char *str, char c);
unsigned int	ft_strlen(char *str);
void			str_write(char *str);
unsigned int	count_occ(char *str, char *occurence);
char			*whereis_cmd(char **cmd, char **env);
char			**push_arr(char **arr, char *to_add);
void			pipex(t_list lst);
void			free_that_matrice(char **matrice);
t_list			get_infile(t_list lst, char **argv);
t_list			get_outfile(t_list lst, char **argv);
t_cmd			get_cmd(char *argv_x, char **env, int code_error);
unsigned int	is_path_ok(char *real_path, char **cmd, t_list lst, char *str);
char			*get_shell(char **env);
unsigned int	count_len_array(char **arr);
char			*ft_strdup(char *str);
char			*get_shell(char **env);
char			**get_var_path_env(char **env, char *to_find);
char			*ft_strjoin(char const *s1, char const *s2);
int				start_with(char *str, char *occurence);
void			free_lst(t_list lst);

#endif
