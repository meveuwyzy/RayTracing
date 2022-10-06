/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:13:04 by student           #+#    #+#             */
/*   Updated: 2020/11/17 21:04:03 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int					get_next_line(int fd, char **line);
int					check_n(char *between);
int					ft_strlen(char *str);
int					check_read(int fd, char **line);
char				*get_left(char *between, int *flag);
char				*get_right(char *between, int *flag);
char				*ft_glue(char *between, char *buff, int *flag);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
