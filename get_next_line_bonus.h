/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdiakit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:33:15 by abdiakit          #+#    #+#             */
/*   Updated: 2024/04/17 17:33:18 by abdiakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

void				ft_bzero(void *dest, size_t n);
char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strchr(char *str, int c);
size_t				ft_strlen(char *s);

#endif
