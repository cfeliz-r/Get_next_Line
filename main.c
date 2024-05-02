/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.your42network.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:47:41 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/05/02 22:31:18 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
        perror("Error opening files");
        return 1;
    }

    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);
    char *line3 = get_next_line(fd3);

    while (line1 || line2 || line3) {
        if (line1) {
            printf("File 1: %s", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        if (line2) {
            printf("File 2: %s", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
        if (line3) {
            printf("File 3: %s", line3);
            free(line3);
            line3 = get_next_line(fd3);
        }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}

