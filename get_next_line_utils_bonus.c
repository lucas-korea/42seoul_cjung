/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:16:47 by cjung             #+#    #+#             */
/*   Updated: 2021/01/24 00:03:30 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s1)
{
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*result;
	char	*dum;

	len = ft_strlen(s1);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dum = result;
	while (*s1)
		*result++ = *s1++;
	*result = 0;
	return (dum);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*result;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	if (!(result = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	i--;
	while (++i < total_len)
		result[i] = s2[i - len1];
	result[i] = 0;
	free(s1);
	s1 = 0;
	return (result);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
