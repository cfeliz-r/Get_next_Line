/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.your42network.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:46:25 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/05/05 02:46:32 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = 0;
		i++;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	while (*str != '\0' && (char)c != *str)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	aux = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j] != '\0')
			aux[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		aux[i++] = s2[j++];
	aux[i] = '\0';
	free(s1);
	return (aux);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*aux;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (len == 0)
		return (NULL);
	if (len > (ft_strlen(s + start)))
		len = ft_strlen(s + start);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (!aux)
	{
		free(aux);
		return (NULL);
	}
	while (len-- && *s)
	{
		aux[i] = s[start];
		i++;
		start++;
	}
	aux[i] = '\0';
	return (aux);
}
