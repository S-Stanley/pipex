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
# include <stdio.h>

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

unsigned int	ft_strlen(char *str);
void			str_write(char *str);
unsigned int	count_occ(char *str, char *occurence);
char			**ft_split(char *to_split, char *splitter);
char			*ft_concat(char *str1, char *str2);
char			*whereis_cmd(char **cmd, char **env);
char			**get_path_var(char **cmd, char **env);
char			**push_arr(char **arr, char *to_add);
void			pipex(t_list lst);
void			free_that_matrice(char **matrice);
t_list			get_infile(t_list lst, char **argv);
t_list			get_outfile(t_list lst, char **argv);
t_cmd			get_cmd(t_list lst, char *argv_x, char **env);
void			check_if_real_path_ok(char *real_path, char **cmd);

#endif
