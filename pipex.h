/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:18:57 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/05 00:45:34 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_cmd
{
	char	*valid_path;
	char	***command;
	int		pipe[2];
	char	*infile_fd;
	char	*outfile_fd;
	char	**possible_paths;
}	t_cmd;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);

void	init_all(char **argv, t_cmd *cmd, char **envp);
void	do_dup(t_cmd *cmd, int i);
int		child_process(t_cmd *cmd, char **envp, int *process_id, int i);
char	*find_path(char**envp);
char 	*find_valid_path(t_cmd *cmd, char **current_cmd);

#endif