/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.your42network.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:34:20 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/05/02 19:52:03 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * The MAX_FD macro is defined based on the max number of file descriptors
 * based on my current OS and what I found online (MacOS Ventura 13.0)
 * (this information is particularly hard to find, or I just don't know 
 * what to search for on Google)
 */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# define MAX_FD 10240
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

#endif
