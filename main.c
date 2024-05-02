/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.your42network.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:47:41 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/05/02 20:55:14 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
#include <stdio.h>

#include <fcntl.h> 
#include <stdlib.h>
int main ()
{	
	char *archivo = "file.txt";
	int fd = open(archivo, O_RDONLY);
	char *line;
	while((line = get_next_line(fd)) != NULL);
	{
	printf("%s", line);
	free (line);
	}
	close(fd);
	return 0;
} 

