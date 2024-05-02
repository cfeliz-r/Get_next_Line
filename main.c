/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.your42network.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:59:16 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/05/03 01:09:08 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"
int main ()
{
	const char *file1 = "file1.txt";
	const char *file2 = "file2.txt";
	const char *file3 = "file3.txt";

	int fd1 = open(file1, O_RDONLY);
	int fd2 = open(file2, O_RDONLY);
	int fd3 = open(file3, O_RDONLY);
	if (fd1 == -1 || fd2 ==-1 || fd3 == -1)
	{
		perror("ERROR");
		return 1;
	}
	char *line1 = get_next_line(fd1);
	while (line1)
	{
		printf("%s", line1);
		free(line1);
		line1 = get_next_line(fd1);

	}
	char *line2 = get_next_line(fd2);
	while (line2)
          {
                  printf("%s", line2);
                  free(line2);
                  line2 = get_next_line(fd2);
 
          }
	char *line3 = get_next_line(fd3);
	while (line3)
          {
                  printf("%s", line3);
                  free(line3);
                  line3 = get_next_line(fd3);
 
          }
	
	
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;

}
