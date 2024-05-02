/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.your42network.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:48:45 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/05/02 21:46:05 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

typedef struct s_file_state {
    int fd;
    char *buffer;
} t_file_state;

static t_file_state *initialize_state(int fd, t_file_state *state);
static char *_fill_line_buffer(t_file_state *state);
static char *_set_line(char **line_buffer);
static char *ft_strchr(const char *s, int c);

static t_file_state *current_state = NULL;

char *get_next_line(int fd)
{
    static char *left_c = NULL;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(left_c);
        left_c = NULL;
        return NULL;
    }

    current_state = initialize_state(fd, current_state);
    if (!current_state)
        return NULL;

    line = _fill_line_buffer(current_state);
    if (!line)
        return NULL;

    left_c = _set_line(&line);
    return line;
}

static t_file_state *initialize_state(int fd, t_file_state *state)
{
    if (!state || state->fd != fd)
    {
        free(state);
        state = malloc(sizeof(t_file_state));
        if (!state)
            return NULL;
        state->fd = fd;
        state->buffer = ft_strdup("");  // Initialize with an empty buffer
    }
    return state;
}

static char *_fill_line_buffer(t_file_state *state)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t b_read;

    b_read = read(state->fd, buffer, BUFFER_SIZE);
    if (b_read < 0)
    {
        free(state->buffer);
        state->buffer = NULL;
        return NULL;
    }

    buffer[b_read] = '\0';
    char *new_buffer = ft_strjoin(state->buffer, buffer);
    free(state->buffer);
    state->buffer = new_buffer;

    return ft_strchr(state->buffer, '\n') ? state->buffer : NULL;
}

static char *_set_line(char **line_buffer)
{
    char *line_end = ft_strchr(*line_buffer, '\n');
    char *line;
    if (line_end)
    {
        *(line_end + 1) = '\0';  // Null-terminate at the newline character
        line = ft_strdup(*line_buffer);
        char *new_start = ft_strdup(line_end + 1);
        free(*line_buffer);
        *line_buffer = new_start;
        return line;
    }
    return NULL;
}

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}

