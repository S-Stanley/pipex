/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:10:00 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/10 17:26:08 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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
void		str_write(char *str);
unsigned int	count_occ(char *str, char *occurence);
char		**ft_split(char *to_split, char *splitter);
char		*ft_concat(char *str1, char *str2);
char		*whereis_cmd(char **cmd, char **env);
char		**get_path_var(char **cmd, char **env);

#endif
