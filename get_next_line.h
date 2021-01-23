/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:04:30 by cjung             #+#    #+#             */
/*   Updated: 2021/01/24 00:07:23 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
int			is_newline(char *buf);
void		split_line(char **r_thread, char **line);
int			return_function(char **r_thread, char **line, int read_len);

char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

#endif
